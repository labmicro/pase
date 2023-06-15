# Automatic Testing in Embedded Systems

This repository contains the firmware of a simple project used as an example in a guide to implementing the Continuous Integration process in the development of embedded systems, including automated testing of actual hardware. Also are avaiable an [spanish version](#pruebas-automáticas-en-sistemas-embebidos)


## Table of Contents

- [License](#license)

## License

This project is distributed under the terms of the [MIT](https://spdx.org/licenses/MIT.html) license.

-----

# Pruebas Automáticas en Sistemas Embebidos

Este repositorio contiene el firmware de un proyecto simple utilizado como ejemplo en una guía para implementar el proceso de Integración Continua en el desarrollo de sistemas embebidos, incluyendo pruebas automatizadas sobre el hardware real.

## Contenido

- [Licencia](#licencia)

## Bitacora

1. Generar una clave SSH para el acceso al repositorio de GitHub
2. Autorizar la parte pública de la clave en el repositorio de GitHub
3. Definir la parte privada de la clave en Jenkins (Usuario: ¿Git? )
4. Crear una tarea usando un proyecto del tipo Pipelinee
5. Configurar resultados de pruebas (plugin xUnit)
https://embeddedartistry.com/blog/2019/02/25/unit-testing-and-reporting-on-a-build-server-using-ceedling-and-unity/
6. Configurar el reporte de cobertura (plugin Code Coverage)

## Licencia

Este proyecto se distribuye bajo los terminas de la licencia [MIT](https://spdx.org/licenses/MIT.html).

@startuml
skinparam componentStyle uml1

[PREAT] --> Cliente

Cliente ..> [Siru]: implementa
frame "Computadora" {
	[Siru]
}

[PREAT] --> Servidor
frame "ATE"{
	[Ruwaq]
}

Servidor ..> Ruwaq: implementa
[Ruwaq] --> [Muju]

frame "DUT"{
	[PASE]
}

[PASE] --> [Muju]
@enduml

@startuml
skinparam componentStyle uml1
frame "Raspberry Pi" {
frame "Docker" {
  [Builder] <.. [Jenkins]
  [Testing] <.. [Jenkins]
  [Jenkins] ..> [Traefik]
  [Jenkins] ..> [Portainer]

}
[Docker] -down-> [DietPi]
}
frame "ATE-EDU-CIAA-NXP" {
  component "EDU-CIAA-NXP" as CA
  component "Placa ATE" as AA
  [CA] <--> [AA]
}
frame "DUT-EDU-CIAA-NXP" {
  component "EDU-CIAA-NXP" as CB
  component "Placa PASE" as PA
  [PA] <--> [CB]
}
[AA] <--> [PA]

frame "ATE-BLUE-PILL" {
  component "EDU-CIAA-NXP" as BA
  component "Placa ATE" as AB
  [BA] <--> [AB]
}
frame "DUT-BLUE-PULL" {
  component "BLUE-PILL" as BB
  component "Placa PASE" as PB
  [PB] <--> [BB]
}
[AB] <--> [PB]

[CA] <-right-> [Raspberry Pi]
[CB] <-right-> [Raspberry Pi]
[Raspberry Pi] <-right-> [BA]
[Raspberry Pi] <-right-> [BB]
@enduml


@startuml
skinparam componentStyle uml1

frame "ATE" {
  frame "EDU-CIAA-NXP/BLUE-PILL" as BoardATE {
    component "Muju" as MujuATE
    [Ruwaq] --> [MujuATE]
  }
  component "Hardware" as HwATE
  [MujuATE] --> [HwATE]
}


frame "DUT" {
  frame "EDU-CIAA-NXP/BLUE-PILL" as BoardDUT {
    component "Muju" as MujuDUT
    [PASE] --> [MujuDUT]
  }
  component "Hardware" as HwDUT
  [MujuDUT] --> [HwDUT]
}


frame "Raspberry Pi" {
  frame "Jenkins" {
    component "PASE" as PaseServer
    [PaseServer] --> [SIRU]
  }
  component "Hardware" as HwDUT
}

@enduml
