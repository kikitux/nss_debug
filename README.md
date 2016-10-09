# nss_debug

## How to use/build

### build
```
git clone https://github.com/kikitux/nss_debug
cd nss_debug
mkdir build
cd build
cmake ..
make
make install
sudo ldconfig
```

### use

```
This will change soon
```


in `/etc/nsswitch.conf` add `debug` or `last` to hosts:

```
# /etc/nsswitch.conf
#..
hosts:          debug files dns last
..
```

As today, the current session should start giving you information over the console using `stderr`

```
$ ping -w1 -c1 non-existing-host.not-a-domain
NSS DEBUG: command: ping, function: _nss_debug_gethostbyname2_r, dst: non-existing-host.not-a-domain, ppid: 24029
sample.counter:1|c|#command:ping,function:_nss_debug_gethostbyname2_r,nss:DEBUG,src:desktop,dst:non-existing-host.not-a-domain,ppid:24029
NSS LAST: command: ping, function: _nss_last_gethostbyname2_r, dst: non-existing-host.not-a-domain, ppid: 24029
sample.counter:1|c|#command:ping,function:_nss_last_gethostbyname2_r,nss:LAST,src:desktop,dst:non-existing-host.not-a-domain,ppid:24029
ping: unknown host non-existing-host.not-a-domain
```

Also in syslog:

```
$ tail -f /var/log/syslog
Oct 10 01:11:48 localhost ping: NSS DEBUG: command: ping, function: _nss_debug_gethostbyname2_r, dst: non-existing-host.not-a-domain, ppid: 24029
Oct 10 01:11:48 localhost ping: NSS LAST: command: ping, function: _nss_last_gethostbyname2_r, dst: non-existing-host.not-a-domain, ppid: 24029
```

And metrics are being sent to datadog under `sample.counter`

## Why

## How

## ToDo

- This readme
- Allow set metric name
- Allow choose on CMakeList if we want `debug->console`
- Allow choose on CMakeList if we want `debug->syslog`
- Allow choose on CMakeList if we want `debug->ddog`
- Add facility: ie `module:hosts` to tag
- Add protocol
- check others that are useful 


```
ethers
group
gshadow
hosts
netgroup
networks
passwd
protocols
rpc
services
shadow
```
