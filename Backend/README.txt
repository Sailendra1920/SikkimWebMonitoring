MAKE SURE YOU HAVE CURL INSTALLED IN YOUR COMPUTER 
	sudo apt-get install libcurl4-openssl-dev
To run the code: 
		gcc app.c -lcurl  -L/usr/include/mysql -lmysqlclient

This is a Sikkim Public Services Website Monitoring app used to monitor the status of the webpages.
Command curl -I "<URL>"
	- gives the http head of the url without the body
	
libcurl CURLOPT_NOBODY 
	- does the same thing in C

The HTTP response status code 302 Found is a common way of performing URL redirection. The HTTP/1.0 specification (RFC 1945) initially defined this code, and gave it the description phrase "Moved Temporarily" rather than "Found".

An HTTP response with this status code will additionally provide a URL in the header field Location. This is an invitation to the user agent (e.g. a web browser) to make a second, otherwise identical, request to the new URL specified in the location field. The end result is a redirection to the new URL.

Many web browsers implemented this code in a manner that violated this standard, changing the request type of the new request to GET, regardless of the type employed in the original request (e.g. POST).[1] For this reason, HTTP/1.1 (RFC 2616) added the new status codes 303 and 307 to disambiguate between the two behaviours, with 303 mandating the change of request type to GET, and 307 preserving the request type as originally sent. Despite the greater clarity provided by this disambiguation, the 302 code is still employed in web frameworks to preserve compatibility with browsers that do not implement the HTTP/1.1 specification.[2] 
