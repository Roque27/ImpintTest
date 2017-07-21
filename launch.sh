#!/bin/sh

    > salida.xml
    ../Ora2Xml -user=lgas/taxi@sict2 -wenc=iso-8859-1 -ofile=salida.xml impint_doc.xml impint_doc.param.xml
    cat salida.xml | ./XMLD
    echo ""