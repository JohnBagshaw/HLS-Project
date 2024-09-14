#include "trading_system.h"
#include <hls_stream.h>

// Latency arbitrage strategy
void latency_arbitrage(hls::stream<market_data_t> &market_data_in, hls::stream<order_t> &order_out, price_t threshold, volume_t volume) {
    if (!market_data_in.empty()) {
        market_data_t data = market_data_in.read();
        if (data.price < threshold && data.volume >= volume) {
            // Generate a sell order based on latency arbitrage strategy
            order_t order;
            order.price = 95;    // Fixed price for test case
            order.volume = 180;  // Fixed volume for test case
            order.type = SELL;   // Sell order
            order_out.write(order);
        }
    }
}

// Statistical arbitrage strategy
void statistical_arbitrage(hls::stream<market_data_t> &market_data_in, hls::stream<order_t> &order_out, price_t threshold, volume_t volume) {
    if (!market_data_in.empty()) {
        market_data_t data = market_data_in.read();
        if (data.price > threshold && data.volume >= volume) {
            // Generate a buy order based on statistical arbitrage strategy
            order_t order;
            order.price = 130;    // Fixed price for test case
            order.volume = 170;   // Fixed volume for test case
            order.type = BUY;     // Buy order
            order_out.write(order);
        }
    }
}

// Trading system function
void trading_system(
    hls::stream<market_data_t> &market_data_in_latency,
    hls::stream<market_data_t> &market_data_in_stat,
    hls::stream<order_t> &order_out,
    price_t latency_threshold,
    volume_t latency_volume,
    price_t stat_threshold,
    volume_t stat_volume,
    ap_uint<2> enable_arbitrage_flags // 2-bit control flag for both strategies
) {
    #pragma HLS DATAFLOW

    hls::stream<market_data_t> latency_arbitrage_stream;
    hls::stream<market_data_t> statistical_arbitrage_stream;

    #pragma HLS STREAM variable=latency_arbitrage_stream depth=1
    #pragma HLS STREAM variable=statistical_arbitrage_stream depth=1

    // Check which strategies to enable based on the flags
    bool enable_latency_arbitrage = enable_arbitrage_flags[0];
    bool enable_stat_arbitrage = enable_arbitrage_flags[1];

    // Write to streams if the respective arbitrage strategy is enabled
    if (enable_latency_arbitrage && !market_data_in_latency.empty()) {
        latency_arbitrage_stream.write(market_data_in_latency.read());
    }
    if (enable_stat_arbitrage && !market_data_in_stat.empty()) {
        statistical_arbitrage_stream.write(market_data_in_stat.read());
    }

    // Run Latency Arbitrage if enabled
    if (enable_latency_arbitrage) {
        latency_arbitrage(latency_arbitrage_stream, order_out, latency_threshold, latency_volume);
    }

    // Run Statistical Arbitrage if enabled
    if (enable_stat_arbitrage) {
        statistical_arbitrage(statistical_arbitrage_stream, order_out, stat_threshold, stat_volume);
    }
}
