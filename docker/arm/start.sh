#/bin/sh

# rm -f agent-key agent-key.pub
# ssh-keygen -f agent-key -m PEM -t rsa -N ""
pub_key="ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQCrcrladVWO7gD3J7I1krfufDdqZ2ekh0xmSoEhrBQ32mItezeTkB6xgt+9eYR4thQ68bbRfJ2yJLRkHuH8VVzsX9D5ZkbWS45N+FeOOMFYZdLefiSISE+mflHP8Zobyd6kEtTZbueQibN64Hv0NEMETthMRWnDPX/+AQ2UucIvowgHWEAN2zyIvaz2KJ4stokOLtPaTSalSssPs6zCrCy7+lK/bu8RHmr+rCkuFrMghzS/zskgsu3LbjgrboJJZNXP5jXf/oAHL+898dxCxYmA4esoZlvNZX2O6IGKXpUB4WRoJsYiUxiSxQsaRrI0tcAwDRQME2qBQL9MfMYjT1I/fi0t7AKKk/herEcUHKDkYjkDSVxNOYXdVC1grV1AXlWE527aLfjmHRbuRPIHOkAhXIlXJBq58KrL4KIykvgiaXbeLONJS7WQ/eyfcBCWQ2lVIsZB63mL8lS5NWIkWDNDC9jjjr2fLxP9EvfMy+0gbQflgZnW39jgTEr6lkhpDkU="

docker build --tag labmicro/arm-agent:lts .
docker run -d --restart=on-failure --name "jenkins.arm" --ip 172.17.0.4 --privileged -v /dev/bus/usb:/dev/bus/usb -v /dev/ttyUSB1:/dev/ttyUSB1 labmicro/arm-agent:lts "$pub_key"
