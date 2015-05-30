# Introduction #

How to build.


# Details #

Add your content here.  Format your content with:
Text in **bold** or _italic_
Headings, paragraphs, and lists
Automatic links to other wiki pages
  * Package should install(assume your source is path/src):
  * 1. scons
  * 2. Install all the packages to path/third\_party:
    * boost1.39
      * should install to path/third\_party/boost, like: ./bootstrap.sh --prefix=path/third\_party --libdir=path/third\_party/boost/lib --includedir=path/third\_party/boost/include
    * gflag
      * Install to path/third\_party/gflag
    * glog
      * Install to path/third\_party/glog with ./configure --with-gflags=path/third\_party/gflags
    * protobuf
      * Install to path/third\_party/protobuf
    * gtest
      * Install to path/third\_party/gtest
    * tcmalloc (for heap checker)
      * Install to /usr/lib or /usr/local/lib, be sure to set the LD\_LIBRARY\_PATH when can't find the lib.
  * run scons under path/src