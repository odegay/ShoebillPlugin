#Buildmachine for ShoebillPlugin compilation
FROM i386/debian

#update
RUN apt-get update
#INSTALL JAVA RUNTIME
RUN apt-get install -y default-jre
#INSTALL JAVA DK
RUN apt-get install -y default-jdk
#update
RUN apt-get update
#INSTALL build essentials including g++ which is C++ compiler on Linux
RUN apt-get install build-essential
# Set the working directory to /app
WORKDIR /app
#CLONE LaTEST ShoebillPLUGIN version
RUN git clone https://github.com/odegay/ShoebillPlugin.git
# Set the working directory to /SHoebillPLugin
WORKDIR /app/SðoebillPlugin
#running build
RUN ./build.sh

