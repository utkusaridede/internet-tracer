#!/bin/bash

ifconfig wlan0 down
iwconfig wlan0 mode monitor
ifconfig wlan0 up
iwconfig wlan0 channel 7
timeout 20 tcpdump -i wlan0 -n -s 64 -w ekraninkokusu.pcap
ifconfig wlan0 down
iwconfig wlan0 mode managed
ifconfig wlan0 up
dhclient wlan0
