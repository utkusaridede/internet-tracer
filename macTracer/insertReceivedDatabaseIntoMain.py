import sqlite3
import os

conn = sqlite3.connect('/home/utku/summerseed/internetTracer/sniffer/data/mainSniff.sqlite')
c = conn.cursor()
c.execute("attach '/home/utku/summerseed/internetTracer/sniffer/data/sniff.sqlite' as s;")
c.execute("insert into packets select * from s.packets;")
conn.commit()
conn.close()
os.system("rm /home/utku/summerseed/internetTracer/sniffer/data/sniff.sqlite")