import json
import urllib2

#req = urllib2.Request("http://www.macvendorlookup.com/api/v2/10:bf:48:1c:94:55")
req = urllib2.Request("http://www.macvendorlookup.com/api/v2/18:cf:5e:90:4b:f7")
opener = urllib2.build_opener()
f = opener.open(req)
json = json.loads(f.read())
print json
print json[0]['company']

