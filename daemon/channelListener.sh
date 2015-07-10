#!/bin/bash

ifconfig wlan0 down
iwconfig wlan0 mode monitor
ifconfig wlan0 up
iwconfig wlan0 channel 7
timeout 10 tcpdump -i wlan0 -n -s 64 -w ../sniffer/input/interAir.pcap
ifconfig wlan0 down
iwconfig wlan0 mode managed
ifconfig wlan0 up
dhclient wlan0
cd ../sniffer
python air_visualizer.pyc input/interAir.pcap
nc 192.168.43.232 8001 < data/sniff.sqlite
#rm /home/utku/Repositories/interTracer/internetTracer/sniffer/data/sniff.sqlite
#rm /home/utku/Repositories/interTracer/internetTracer/sniffer/input/interAir.pcap
