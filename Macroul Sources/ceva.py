import google

import sys
target = open('output.txt', 'w');
target.truncate();
for x in google.search(sys.argv[1],tld=sys.argv[2],lang=sys.argv[3],num=2,start=0,stop=1,pause=0.0):
	target.write(x);
	target.write("\n");
target.close();