# Introduction #
How to configure linux kenerl parameter to support large connection(over 40K) in the Ubuntu.
  * set the file size: /etc/security/limits.conf.
  * echo "32768 61000" >/proc/sys/net/ipv4/ip\_local\_port\_range, or   sysctl -w net.ipv4.ip\_local\_port\_range ='32768 61000'