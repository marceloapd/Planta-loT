## Sobre o projeto

![Sem_título-removebg-preview](https://user-images.githubusercontent.com/71731452/111224894-d263c880-85bd-11eb-939b-ff83d24d79ed.png)

Este projeto consiste em desenvolver um dispositivo capaz de notificar as necessidades de uma planta domestica.

## Features

* Conexão ao Wifi via WPS
* Auto-save da senha da ultima conexão Wifi

### Construido com

* [Proteus Design Suite](https://www.labcenter.com/)
* [PlatformIO](https://platformio.org/)


## Começando

* Crie uma conta no [ThingSpeak](https://thingspeak.com/)
* Vincule uma conta do twitter ao ThingSpeak.
* Crie um "channel" no ThingSpeak com 3 "Fields" para registrar as leituras(umidade_solo, umidade_ar e temperatura).

![Sem título](https://user-images.githubusercontent.com/71731452/111236804-78b9c900-85d2-11eb-886d-4f2d571e07b4.png)



### Pré-requisitos

* Sensor de Umidade do Solo
* ESP8266
* DHT 22

### Instalação

1. Comece montando o hardware baseado nesse [esquema eletrico](https://user-images.githubusercontent.com/71731452/111225844-0db2c700-85bf-11eb-83d9-2f78065c2d21.jpg) 
2. Obtenha o PlataformIO [https://platformio.org/](https://platformio.org/)
3. Clone o repositorio https://github.com/marceloapd/PlantaloT
4. Importe o projeto para o PlataformIO
5. Suba o firmware para o ESP8266
   

## Uso

Atualmente o dispositivo de PlantaloT consegue notificar via twitter o valor de seus sensores de umidade do solo, umidade do ar e temperatura

Para obter exemplos, abra o [twitter](https://twitter.com/do_planta)


## Roadmap

Consulte os [issues](https://github.com/marceloapd/PlantaloT/issues) para obter uma lista de recursos propostos (e problemas conhecidos).



## Contribuindo

As contribuições são o que tornam a comunidade do 'open source' um lugar incrível para aprender, inspirar e criar. Quaisquer contribuições que você fizer serão * bem recebidas *.

## Licença

Distributed under the MIT License. See `LICENSE` for more information.



## Contato

Marcelo Assis - [@marceloapda](https://twitter.com/marceloapda) - marcelo.apdassis@gmail.com

Link do Projeto: [https://github.com/marceloapd/PlantaloT](https://github.com/marceloapd/PlantaloT)

