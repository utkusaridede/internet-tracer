import sqlite3
import os

while 1:
	os.system(
		"nc -l -p 8001 -q 1 > /home/utku/summerseed/internetTracer/sniffer/data/sniff.sqlite")
   
	con = sqlite3.connect(
		'/home/utku/summerseed/internetTracer/sniffer/data/mainSniff.sqlite')
	d = con.cursor()
	d.execute("select max(id) from packets")
	lastId = d.fetchall()
        lastId = str(lastId)
        lastId = lastId.replace("[(", "")
        lastId = lastId.replace(",)]", "")
	con.close()
	print lastId

	connn = sqlite3.connect(
		'/home/utku/summerseed/internetTracer/sniffer/data/sniff.sqlite')
	e = connn.cursor()
	e.execute("select id from packets")
	listId = e.fetchall()
	connn.close()

	listId = str(listId)
	listId = listId.replace(" (", "")
	listId = listId.replace(",)", "")

	for Id in listId:
		updatedId = lastId + Id
		print updatedId
		
		connnn = sqlite3.connect(
			'/home/utku/summerseed/internetTracer/sniffer/data/sniff.sqlite')
		g = connnn.cursor()
		g.execute("UPDATE packets SET id=? WHERE id=?", (updatedId, Id))
		connnn.commit()
		connnn.close()

	conn = sqlite3.connect(
		  '/home/utku/summerseed/internetTracer/sniffer/data/mainSniff.sqlite')
	c = conn.cursor()
	c.execute(
		  "attach '/home/utku/summerseed/internetTracer/sniffer/data/sniff.sqlite' as s;")
	c.execute("insert into packets select * from s.packets")
	conn.commit()
	conn.close()
	os.system(
		 "rm /home/utku/summerseed/internetTracer/sniffer/data/sniff.sqlite")
