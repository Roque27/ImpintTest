#!/bin/sh

    ../Ora2Xml -user=lgas/taxi@sict2 -wenc=iso-8859-1 -ofile=salida.xml test.xml
    cat salida.xml | ./XMLD
    echo ""