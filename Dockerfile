#Buildmachine for ShoebillPlugin compilation
#by the recommendation of the 
FROM odegay/oxotaserver_cpp_buildmachine:latest

#update
RUN apt-get update && apt-get upgrade -y

# Set the working directory to /app
WORKDIR /app
RUN dir
#CLONE LATEST ShoebillPLUGIN version
RUN git clone https://github.com/odegay/ShoebillPlugin.git
# Set the working directory to /ShoebillPLugin
WORKDIR /app/ShoebillPlugin
# just in case we have to update the rep
#CMD  ["git pull"]
#running build
CMD  ["./build.sh"]
#RUN ./build.sh



