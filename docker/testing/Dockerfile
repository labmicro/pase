FROM jenkins/ssh-agent:latest
RUN apt-get update && \
    apt-get install --no-install-recommends --yes \
    gcc \
    cppcheck \
    gcovr \
    make \
    ruby && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* && \
    gem install ceedling
