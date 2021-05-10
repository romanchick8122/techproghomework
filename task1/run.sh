#!/bin/bash
mkdir -p $3
find $1 -name "*.$2" | xargs tar -zcf $4
tar -zxf $4 -C $3
echo done
