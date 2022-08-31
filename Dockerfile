FROM debian:latest

RUN apt-get update

RUN apt-get -y install clang gcc make valgrind

WORKDIR /tmp

# ENTRYPOINT [ "/bin/bash", "-c", "make re && \
#          valgrind --leak-check=full \
#          --show-leak-kinds=all \
#          --track-origins=yes \
#          --verbose \
#          ./philo 4 80 10 20 10" ]

