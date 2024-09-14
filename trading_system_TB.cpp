#include "trading_system.h"
#include <iostream>
#include <hls_stream.h>

int main() {
    hls::stream<market_data_t> market_data_in_latency;
    hls::stream<market_data_t> market_data_in_stat;
    hls::stream<order_t> order_out;

    // Test data for Latency Arbitrage and Statistical Arbitrage
    market_data_t latency_data;
    latency_data.price = 100;
    latency_data.volume = 180;

    market_data_t stat_data;
    stat_data.price = 130;
    stat_data.volume = 170;

    // Push test data to input streams
    market_data_in_latency.write(latency_data);
    market_data_in_stat.write(stat_data);

    // Thresholds and volumes for both strategies
    price_t latency_threshold = 95;    // Latency Arbitrage threshold
    volume_t latency_volume = 180;     // Latency Arbitrage volume
    price_t stat_threshold = 120;      // Statistical Arbitrage threshold
    volume_t stat_volume = 170;        // Statistical Arbitrage volume

    // Enable both strategies using ap_uint<2>
    ap_uint<2> enable_arbitrage_flags = 0b11; // Enable both strategies

    // Run the trading system
    trading_system(
        market_data_in_latency,
        market_data_in_stat,
        order_out,
        latency_threshold,
        latency_volume,
        stat_threshold,
        stat_volume,
        enable_arbitrage_flags
    );

    // Read and print results for both strategies
    while (!order_out.empty()) {
        order_t order = order_out.read();
        std::cout << "Generated Latency Arbitrage Order: " << std::endl;
        std::cout << "Price = " << latency_data.price << ", Volume = " << latency_data.volume << ", Type = " 
                  << ((order.type == SELL) ? "Sell" : "Buy") << std::endl;
        
        std::cout << "Generated Statistical Arbitrage Order: " << std::endl;
        std::cout << "Price = " << stat_data.price << ", Volume = " << stat_data.volume << ", Type = " 
                  << ((order.type == BUY) ? "Buy" : "Sell") << std::endl;
    }

    return 0;
}
