#!/bin/bash

cd /home/utku/deneme/sniffer
ifconfig wlan0 down
iwconfig wlan0 mode monitor
ifconfig wlan0 up
iwconfig wlan0 channel 7
timeout 10 tcpdump -i wlan0 -n -s 64 -w /home/utku/deneme/interAir.pcap
ifconfig wlan0 down
iwconfig wlan0 mode managed
ifconfig wlan0 up
dhclient wlan0
python /home/utku/deneme/sniffer/air_visualizer.pyc /home/utku/deneme/interAir.pcap
#nc 192.168.2.224 8001 < /dev/internetTracer/sniff.sqlite
#rm /dev/internetTracer/sniff.sqlite
#rm /dev/internetTracer/interAir.pcap