#!/bin/bash
while true
    do
        echo "hello"
        python test.py > input
        cat input | grep -v "#" | ./a.out > output2
        cat input | grep "#" | sed "s/#//g" > output1
        a=`diff output1 output2`
        if [ "$a" != "" ] ; then
            break
        fi
    done
