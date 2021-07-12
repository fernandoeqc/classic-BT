# Sistema  de comunicação entre rádios AM

A placa ESP32 faz a ponte entre o apk android e o circuito periférico de radiofrequência.

____

### O envio do áudio acontece na seguinte ordem:
``` 
O usuário grava o áudio em WAV, que é codificado em base64 
```
``` 
O aplicativo envia o arquivo base64 via bluetooth serial para o ESP32
```
``` 
O ESP32 converte o arquivo base64 de volta em WAV
```
``` 
O ESP32 envia o áudio WAV pelo circuito do rádio
```

A comunicação entro o ESP32 e o circuito do rádio utiliza a biblioteca `autoAnalogAudio`, em github.com/TMRh20.

_____

## Tarefas a comcluir:
* Implementar a decodificação de base64 para wav
* Testar e utilizar a lib SdFat
