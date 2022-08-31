#!/bin/bash
# docker run --rm -v $PWD:/tmp  "valgrind:1.2"

# To run interactive
docker run -it --rm -v $PWD:/tmp  "interactive_valgrind"