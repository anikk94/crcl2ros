

 

# Installing Xerces c with Ubuntu

From https://www.daniweb.com/hardware-and-software/linux-and-unix/threads/409769/ubuntu-11-10-xerces-c

As far as I'm aware libxerces is the same as pretty much any other library in Debian based systems. It should be available in the repositories (the exact version will depend on which version of Ubuntu you're running).
 
You can use apt-get to install the packages for the library and the dev files.

Then to use them in your C/C++ programs you simply #include the appropriate headers and link with the library when compiling/linking.
 
    sudo apt-get update
    apt-cache search libxerces
    sudo apt-get install libxerces-c3.1 libxerces-c-dev
 
Need include file path CMakeLists.txt:

    include_directories(/usr/include/xercesc)
 
Link library in  CMakeLists.txt:

    link_directories(/usr/lib/x86_64-linux-gnu/)
 
Need to link against libxerces.a in CMakeLists.txt:

    target_link_libraries(nist_fanuc 
    libxerces-c.a  
    ${catkin_LIBRARIES}
    ${Boost_LIBRARIES}
    )
 
 
 
## Installing CodeSynthesis XSD

http://www.codesynthesis.com/products/xsd/download.xhtml

1. Chose the linux deb install file that matches your computer (below 64 bit amd).
2. Download xsd_4.0.0-1_amd64.deb and it will say open with Ubuntu Software Center
3. Click to install, authenticate and add /usr/include/xsd/cxx/xml as include path.
 
Need include file path in CMakeLists.txt:

    include_directories(/usr/include/xsd/cxx/xml)

If you  cannot run Ubuntu software centerto install CodeSynthesis, you can download the source and install it.
You need to go to the web page: http://www.codesynthesis.com/products/xsd/download.xhtml and select:

    xsd-4.0.0-x86_64-linux-gnu.tar.bz2
 
It  will be saved into /usr/local/downloads, but you can save it anywhere. Then cd to where you saved it, and do this:
 
    tar --bzip2 -xvf xsd-4.0.0-x86_64-linux-gnu.tar.bz2 (dash-dash bzip2, dash-xvf)
 
It will create a directory xsd-4.0.0-x86_64-linux-gnu.
 
Make a symbolic link:
 
    ln -s <path/to/xsd-4.0.0-x86_64-linux-gnu/libxsd/xsd /usr/local/include/xsd

e.g., 
	ln -s /usr/local/xsd-4.0.0-x86_64-linux-gnu/libxsd/xsd /usr/local/include/xsd








