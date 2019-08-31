#!/usr/bin/env bash
echo "+++++ Start shell script initiated +++++"
echo "+++++ Pulling latest files from GitHub +++++"
git pull
echo "+++++ Rep up-to-date +++++"
echo " "
echo "Running build.sh"
./build.sh
echo "+++++ build.sh done +++++"