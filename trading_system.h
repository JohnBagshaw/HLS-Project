#ifndef TRADING_SYSTEM_H
#define TRADING_SYSTEM_H

#include <hls_stream.h>
#include <ap_int.h>

// Define the price and volume types
typedef ap_uint<32> price_t;   // 32-bit price data type
typedef ap_uint<16> volume_t;  // 16-bit volume data type

// Define the market data structure
typedef struct {
    price_t price;   // 32-bit price field
    volume_t volume; // 16-bit volume field
} market_data_t;

// Define the order type (Buy/Sell)
typedef enum {
    BUY = 0,
    SELL = 1
} order_type_t;

// Define the order structure
typedef struct {
    price_t price;       // 32-bit price field
    volume_t volume;     // 16-bit volume field
    order_type_t type;   // Buy or Sell order
} order_t;

// Function prototype for the trading system
void trading_system(
    hls::stream<market_data_t> &market_data_in_latency,
    hls::stream<market_data_t> &market_data_in_stat,
    hls::stream<order_t> &order_out,
    price_t latency_threshold,
    volume_t latency_volume,
    price_t stat_threshold,
    volume_t stat_volume,
    ap_uint<2> enable_arbitrage_flags // Control flags for enabling/disabling arbitrage strategies
);

#endif // TRADING_SYSTEM_H
