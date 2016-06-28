## commonC


  C language programming experience summary and lesson learned
  
---

#### nginx
[Nginx](http://nginx.org/)
- LoC: 118k
- Description:

  nginx [engine x] is an HTTP and reverse proxy server, a mail proxy server, and a generic TCP/UDP proxy server, originally written by Igor Sysoev. 
- Usage:

  start nginx, run the executable file. Once nginx is started, it can be controlled by invoking the executable with the -s parameter. Use the following syntax: 
  ``` bash
nginx -s signal

stop — fast shutdown
quit — graceful shutdown
reload — reloading the configuration file
reopen — reopening the log files
  ```
  - configuration file:
  The server requests of images with files from the local directory and sends all other requests to a proxied server; The two servers will be defined o n a single ngninx instance.
  The first server listens on port `8080`, default on 80, and maps all requests to the `data/up1` directory on th local file system. Put index.html file in to data/up1. `root` directive is placed in the `server` context. It could be used when the `localtion` block selected for serving a request does not include own `root` directive.
  The second server configuration puts `proxy_pass` directive with the protocol, name and port of the proxied server specified in the parameter. In the second `location` block, which currently maps requests with the `/images/` prefix to the files under the `data/images` directory, to make it match the requests of images with typical file extension. The parameteris a regular expression matching all URL ending with `.git, .jpg, or .png`. A regular expression should be preceded with `~`. 
    - Proxy server:
    ```    
    server {
        listen 8080;
        root /data/up1;

        location / {
        }
    }

    server {
        location / {
            proxy_pass http://localhost:8080/;
        }

        location ~ \.(gif|jpg|png)$ {
            root /data/images;
        }
    }
    ```

- Reading Codes:
  [Reading notes-1]()

#### cJSON
[cJSON](http://sourceforge.net/projects/cjson/)
* LoC:
* Description:
* Usage:
* Reading Codes:

#### Cmockery
[Cmockery](http://code.google.com/p/cmockery/downloads/list)
* LoC:
* Description:
* Usage:
* Reading Codes:

#### Libev
[Libev](http://software.schmorp.de/pkg/libev.html)
* LoC:
* Description:
* Usage:
* Reading Codes:

#### Memcached
[Memcached](http://memcached.org/)
* LoC:
* Description:
* Usage:
* Reading Codes:

#### Lua
[Lua](http://www.lua.org/)
* LoC:
* Description:
* Usage:
* Reading Codes:

#### Tinyhttpd
[Tinyhttpd](http://sourceforge.net/projects/tinyhttpd/)
* LoC:
* Description:
* Usage:
* Reading Codes:

#### Webbench
[Webbench](http://home.tiscali.cz/~cz210552/webbench.html)
* LoC:
* Description:
* Usage:
* Reading Codes:
