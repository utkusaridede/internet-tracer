import sqlite3
import os


while 1:
	fo = open("data/sniffFileCount.txt","r")
	count = fo.read()
	count = int(count)
	fo.close()
	os.system("nc -l -p 8001 -q 1 > /home/utku/summerseed/internetTracer/sniffer/data/sniff%d.sqlite" % count)
	count = count + 1
	fr = open("sniffFileCount.txt","w")
	fr.write(str(count))
	fr.close()

