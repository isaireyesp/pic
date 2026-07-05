# 🔌 Proyecto con Microcontrolador PIC

Proyecto desarrollado utilizando un **microcontrolador PIC**, enfocado en el diseño, programación e implementación de un sistema electrónico embebido para controlar dispositivos de entrada y salida mediante hardware y software.

El proyecto demuestra el uso de periféricos del microcontrolador, programación en lenguaje C y simulación mediante herramientas de desarrollo para sistemas embebidos.

---


# ✨ Características

* ⚡ Programación de microcontroladores PIC.
* 🔘 Lectura de entradas digitales.
* 💡 Control de salidas digitales.
* ⏱ Uso de temporizadores (Timers).
* 🔄 Manejo de interrupciones.
* 📟 Comunicación con dispositivos externos.
* 🔧 Fácil adaptación a otros proyectos electrónicos.
* 📚 Código organizado y documentado.

---

# 🛠 Tecnologías utilizadas

* Microcontrolador PIC
* Lenguaje C
* MPLAB X IDE
* MPLAB XC8 Compiler
* Proteus (Simulación)
* Git
* GitHub

---

# 📁 Estructura del proyecto

```text
Proyecto-PIC/
│
├── firmware/
│   ├── main.c
│   ├── config.h
│   ├── lcd.c
│   ├── lcd.h
│   ├── sensores.c
│   ├── sensores.h
│   └── utilidades.c
│
├── simulacion/
│   ├── ProyectoPIC.pdsprj
│   └── ProyectoPIC.hex
│
├── esquematico/
│   └── circuito.pdf
│
├── imagenes/
│
└── README.md
```

---

# ⚙️ Requisitos

Para ejecutar o modificar el proyecto se requiere:

* MPLAB X IDE
* Compilador MPLAB XC8
* Proteus (opcional)
* Programador PICkit 3 o PICkit 4
* Microcontrolador PIC

---

# 🔌 Hardware utilizado

El proyecto puede utilizar los siguientes componentes:

* Microcontrolador PIC16F877A (o el modelo correspondiente)
* Protoboard
* Fuente de alimentación de 5V
* Resistencias
* LEDs
* Pulsadores
* Display LCD 16x2
* Sensor(es)
* Buzzer (opcional)
* Relés (opcional)

---

# 🚀 Instalación

## 1. Clonar el repositorio

```bash
git clone https://github.com/tu-usuario/proyecto-pic.git
```

Entrar al proyecto:

```bash
cd proyecto-pic
```

---

## 2. Abrir el proyecto

Abrir el proyecto desde **MPLAB X IDE**.

---

## 3. Compilar

Seleccionar el microcontrolador correspondiente y compilar el proyecto.

Se generará automáticamente el archivo:

```text
dist/default/production/ProyectoPIC.hex
```

---

# ▶️ Simulación

Abrir el archivo del circuito en **Proteus**.

Cargar el archivo **.hex** generado por MPLAB.

Ejecutar la simulación para verificar el funcionamiento del sistema.

---

# 📋 Funcionamiento

El sistema realiza las siguientes tareas:

* Inicializa el microcontrolador.
* Configura los puertos de entrada y salida.
* Lee continuamente las señales provenientes de los sensores o pulsadores.
* Procesa la información recibida.
* Controla los dispositivos de salida según la lógica implementada.
* Ejecuta tareas periódicas mediante temporizadores e interrupciones.

---

# 🔧 Configuración

Antes de compilar verifica:

* Frecuencia del cristal.
* Bits de configuración (Configuration Bits).
* Tipo de oscilador.
* Voltaje de alimentación.
* Pines utilizados.

---

# 📷 Diagrama del circuito

El circuito puede incluir:

* Microcontrolador PIC
* Fuente de alimentación
* Cristal oscilador
* Capacitores
* LEDs indicadores
* Pulsadores
* Pantalla LCD
* Sensores

> Se recomienda incluir una imagen del circuito o el archivo de Proteus en este apartado.

---

# 📊 Aplicaciones

Este proyecto puede adaptarse para:

* Automatización industrial
* Sistemas domóticos
* Control de iluminación
* Alarmas electrónicas
* Sistemas de monitoreo
* Control de motores
* Control de temperatura
* Proyectos educativos

---

# 📱 Compatibilidad

* Windows
* Linux (MPLAB X)
* macOS

Microcontroladores compatibles:

* PIC16F877A
* PIC16F887
* PIC18F4550
* PIC18F4520
* Otros microcontroladores PIC compatibles con XC8

---

# 📈 Ventajas

* Código modular.
* Fácil mantenimiento.
* Bajo consumo energético.
* Arquitectura escalable.
* Compatible con simulación en Proteus.
* Fácil adaptación a otros proyectos.
* Ideal para prácticas de electrónica y sistemas embebidos.

---

# 👨‍💻 Autor

Proyecto desarrollado como práctica de **Microcontroladores PIC**, aplicando conceptos de programación embebida, electrónica digital y diseño de sistemas electrónicos.

---

# 📄 Licencia

Este proyecto puede utilizarse con fines educativos, académicos y de investigación, respetando los créditos correspondientes al autor.
