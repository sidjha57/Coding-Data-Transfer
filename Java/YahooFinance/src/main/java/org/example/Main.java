package org.example;


import com.ea.async.Async;
import yahoofinance.Stock;
import yahoofinance.YahooFinance;

import java.io.IOException;
import java.math.BigDecimal;
import java.time.LocalTime;
import java.util.*;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;

import static jdk.internal.org.objectweb.asm.tree.Util.add;

/*
    NIFTY 50 = ^NSEI
    NIFTY BANK = ^NSEBANK
    NIFTY MIDCAP 50 = ^NSEMDCP50
    NIFTY SMLCAP 50 = NIFTYSMLCAP50.NS
    NIFTY AUTO = ^CNXAUTO
    NIFTY FMCG = ^CNXFMCG
    NIFTY IT = ^CNXIT
    NIFTY METAL = ^CNXMETAL
    NIFTY PHARMA = ^CNXPHARMA
    NIFTY REALTY = ^CNXREALTY
    NIFTY 500 = ^CRSLDX
 */
public class Main {
    public static void main(String[] args) throws IOException {
//        Async.init();
//        List<String> symbols = new ArrayList<String>({{
//            add("^NSEI"),
//
//        }});
        String[] symbols = new String[] {"^NSEI", "^NSEBANK", "^NSEMDCP50", "NIFTYSMLCAP50.NS", "^CNXAUTO", "^CNXFMCG", "^CNXIT", "^CNXMETAL", "^CNXPHARMA", "^CNXREALTY", "^CRSLDX"};
        Map<String, Stock> stocks = YahooFinance.get(symbols);
        Stock NITFY50 = stocks.get("^NSEI");
        Stock NIFTYBANK = stocks.get("^NSEBANK");

//        CompletableFuture<BigDecimal> completableFuture = CompletableFuture.supplyAsync(
//                () -> {
//                    try {
//                        return YahooFinance.get("^CNXIT").getQuote(true).getPrice();
//                    } catch (IOException e) {
//                        throw new RuntimeException(e);
//                    }
//                }
//        );
//        System.out.println(Async.await(completableFuture));
//        while(!completableFuture.isDone()) {
//            System.out.println("CompletableFuture is not finished yet...");
//        }

//            System.out.println(completableFuture.get());


//        BigDecimal price = YahooFinance.get("^CNXIT").getQuote(false).getPrice();
//        BigDecimal previousClose = YahooFinance.get("^CNXIT").getQuote(false).getPreviousClose();
//        BigDecimal change = YahooFinance.get("^CNXIT").getQuote(false).getChange();
//        Double booster = 2.5;
//        BigDecimal perChange = YahooFinance.get("^CNXIT").getQuote(false).getChangeInPercent();
////        System.out.println(price);
//        System.out.println(change);
////        System.out.println(previousClose);
//        System.out.println(perChange);
////        System.out.println(perChange.multiply(BigDecimal.valueOf(booster)));
////
////        BigDecimal score = BigDecimal.ZERO;
////        score = score.add(perChange);
////        System.out.println(score);
//
//        String[] symbols = new String[] {"^NSEI", "^NSEBANK", "^NSEMDCP50", "NIFTYSMLCAP50.NS", "^CNXAUTO", "^CNXFMCG", "^CNXIT", "^CNXMETAL", "^CNXPHARMA", "^CNXREALTY", "^CRSLDX"};
//
//        LocalTime time = LocalTime.now();
//        System.out.println(time.getHour());


//        NITFY50.print();

//        NIFTYBANK.print();
    }
}