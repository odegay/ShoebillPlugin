#Buildmachine for ShoebillPlugin compilation
#by the recommendation of the 
FROM i386/debian

#update
RUN apt-get update
#installing apt utils
RUN apt-get install -y apt-utils
#update
RUN apt-get update
#INSTALL JAVA RUNTIME
RUN apt-get install -y default-jre
#INSTALL JAVA DK
RUN apt-get install -y default-jdk
#update
RUN apt-get update
#INSTALL build essentials including g++ which is C++ compiler on Linux
RUN apt-get install -y build-essential
#INSTALL cmake
RUN apt-get install -y cmake
#install git
RUN apt-get install -y git
#update
RUN apt-get update
#Install libc6
RUN apt-get install libc6-dev
# Set the working directory to /app
WORKDIR /app
#CLONE LATEST ShoebillPLUGIN version
RUN git clone https://github.com/odegay/ShoebillPlugin.git
# Set the working directory to /ShoebillPLugin
WORKDIR /app/ShoebillPlugin
# just in case we have to update the rep
RUN git pull
#RUN 
RUN cat /usr/include/iconv.h
#running build
RUN ./build.sh



