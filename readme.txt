# Sistema de Monitoreo de Calidad del Aire

Este repositorio contiene el código y la documentación para un sistema de monitoreo de calidad del aire diseñado utilizando un ESP32, sensores MQ135 y MQ9, un sensor de temperatura y humedad DHT11, y una pantalla OLED de 128x64. El sistema está pensado para medir concentraciones de CO₂ y CO, así como temperatura y humedad, mostrando los resultados en tiempo real en la pantalla OLED.

---

## **Portada y Video**

# Sistema de Monitoreo de Calidad del Aire

Este repositorio contiene el código y la documentación para un sistema de monitoreo de calidad del aire diseñado utilizando un ESP32, sensores MQ135 y MQ9, un sensor de temperatura y humedad DHT11, y una pantalla OLED de 128x64. El sistema está pensado para medir concentraciones de CO₂ y CO, así como temperatura y humedad, mostrando los resultados en tiempo real en la pantalla OLED.

---

## **Portada y Video**

![Portada del Video](C:/Users/patyc/OneDrive/Escritorio/Sistema_calidad_aire/calidad aire-miniatura)

Mira el video explicativo completo en YouTube: [Ver en YouTube]https://www.youtube.com/watch?v=c_tzG9tjMo8

---

## **Características del Proyecto**

- **Microcontrolador**: ESP32.
- **Sensores**:
  - MQ135: Medición de concentración de CO₂.
  - MQ9: Medición de concentración de CO.
  - DHT11: Lectura de temperatura y humedad.
- **Visualización**:
  - Pantalla OLED de 128x64 pixeles utilizando la biblioteca Adafruit SSD1306.
  - Salida de datos en el monitor serie.
- **Cálculos Implementados**:
  - Cálculo de Rs (resistencia del sensor) a partir de un divisor de tensión.
  - Cálculo de Ro (resistencia de referencia en aire limpio).
  - Conversión de Rs/Ro a concentraciones de gas (PPM) mediante relaciones logarítmicas.

---

## **Estructura del Repositorio**

1. **Código Fuente**:
   - Archivo principal del programa: `calidad_aire.ino`.
   - Incluye configuración de hardware, cálculos de PPM y visualización en pantalla OLED.

2. **Documentación**:
   - Archivo Word: `Sensor MQ135.docx`. Contiene detalles técnicos sobre el funcionamiento de los sensores y las ecuaciones utilizadas.

3. **Guía de Uso**:
   - Este archivo `README.md` para la descripción general del proyecto.

---

## **Requisitos de Hardware**

- **ESP32**: Microcontrolador con capacidades de Wi-Fi y Bluetooth.
- **Sensor MQ135**: Para detección de CO₂.
- **Sensor MQ9**: Para detección de CO.
- **Sensor DHT11**: Para medir temperatura y humedad.
- **Pantalla OLED**: Modelo SSD1306 (128x64 pixeles).
- Resistencias de carga: 20 kΩ.
- Conexiones y cables.

---

## **Instalación y Configuración**

1. **Instalar Bibliotecas Necesarias**:
   - Adafruit GFX: `Adafruit_GFX.h`
   - Adafruit SSD1306: `Adafruit_SSD1306.h`
   - DHT Sensor Library: `DHT.h`

   Puedes instalarlas desde el Administrador de Bibliotecas del IDE de Arduino.

2. **Conexiones del Hardware**:
   - **MQ135**: Conecta la salida analógica al pin 34 del ESP32.
   - **MQ9**: Conecta la salida analógica al pin 35 del ESP32.
   - **DHT11**: Conecta la salida digital al pin 19 del ESP32.
   - **Pantalla OLED**: Conecta SDA y SCL a los pines correspondientes del ESP32 (I2C).

3. **Configura y Sube el Código**:
   - Abre el archivo `calidad_aire.ino` en el IDE de Arduino.
   - Selecciona la placa ESP32 y el puerto COM correcto.
   - Sube el código al ESP32.

---

## **Cálculos Implementados**

### **Cálculo de Rs**
Rs se calcula a partir de un divisor de tensión:

\[
Rs = RL \times \left( \frac{Vs - Vm}{Vm} \right)
\]

Donde:
- RL: Resistencia de carga (20 kΩ).
- Vs: Voltaje de alimentación (5V).
- Vm: Voltaje medido por el ESP32.

### **Cálculo de Ro**
Ro se determina en aire limpio usando la relación Rs/Ro proporcionada por la hoja de datos del sensor:

- Para el MQ135: Rs/Ro = 3.8.
- Para el MQ9: Rs/Ro = 9.9.

### **Cálculo de PPM**
Se utiliza una relación logarítmica entre Rs/Ro y PPM:

\[
PPM = 10^{\frac{\log(Rs/Ro) - b}{m}}
\]

Donde:
- m: Pendiente de la curva.
- b: Intersección de la curva.

Valores para los sensores:
- **MQ135**:
  - m = -0.3679
  - b = 0.815
- **MQ9**:
  - m = -0.4101
  - b = 1.075

---

## **Visualización en Pantalla OLED**

Los datos procesados se despliegan en la pantalla OLED con el siguiente formato:
- Concentración de CO₂ en PPM.
- Concentración de CO en PPM.
- Temperatura en °C.
- Humedad relativa en %.

---

## **Aplicaciones**

- Monitoreo de calidad del aire en espacios cerrados.
- Sistemas de automatización para el control ambiental.
- Proyectos educativos para aprender sobre sensores y cálculos logarítmicos.
- Base para sistemas IoT avanzados con envío de datos a la nube.

---

## **Contribuciones**
Este proyecto está abierto a mejoras. Si deseas contribuir, puedes hacerlo mediante pull requests o reportando problemas en la sección de issues.

---

## **Licencia**
Este proyecto está licenciado bajo [MIT License](LICENSE), por lo que es de uso libre para proyectos personales y educativos.



Mira el video explicativo completo en YouTube: [Ver en YouTube]https://www.youtube.com/watch?v=c_tzG9tjMo8

---

## **Características del Proyecto**

- **Microcontrolador**: ESP32.
- **Sensores**:
  - MQ135: Medición de concentración de CO₂.
  - MQ9: Medición de concentración de CO.
  - DHT11: Lectura de temperatura y humedad.
- **Visualización**:
  - Pantalla OLED de 128x64 pixeles utilizando la biblioteca Adafruit SSD1306.
  - Salida de datos en el monitor serie.
- **Cálculos Implementados**:
  - Cálculo de Rs (resistencia del sensor) a partir de un divisor de tensión.
  - Cálculo de Ro (resistencia de referencia en aire limpio).
  - Conversión de Rs/Ro a concentraciones de gas (PPM) mediante relaciones logarítmicas.

---

## **Estructura del Repositorio**

1. **Código Fuente**:
   - Archivo principal del programa: `calidad_aire.ino`.
   - Incluye configuración de hardware, cálculos de PPM y visualización en pantalla OLED.

2. **Documentación**:
   - Archivo Word: `Sensor MQ135.docx`. Contiene detalles técnicos sobre el funcionamiento de los sensores y las ecuaciones utilizadas.

3. **Guía de Uso**:
   - Este archivo `README.md` para la descripción general del proyecto.

---

## **Requisitos de Hardware**

- **ESP32**: Microcontrolador con capacidades de Wi-Fi y Bluetooth.
- **Sensor MQ135**: Para detección de CO₂.
- **Sensor MQ9**: Para detección de CO.
- **Sensor DHT11**: Para medir temperatura y humedad.
- **Pantalla OLED**: Modelo SSD1306 (128x64 pixeles).
- Resistencias de carga: 20 kΩ.
- Conexiones y cables.

---

## **Instalación y Configuración**

1. **Instalar Bibliotecas Necesarias**:
   - Adafruit GFX: `Adafruit_GFX.h`
   - Adafruit SSD1306: `Adafruit_SSD1306.h`
   - DHT Sensor Library: `DHT.h`

   Puedes instalarlas desde el Administrador de Bibliotecas del IDE de Arduino.

2. **Conexiones del Hardware**:
   - **MQ135**: Conecta la salida analógica al pin 34 del ESP32.
   - **MQ9**: Conecta la salida analógica al pin 35 del ESP32.
   - **DHT11**: Conecta la salida digital al pin 19 del ESP32.
   - **Pantalla OLED**: Conecta SDA y SCL a los pines correspondientes del ESP32 (I2C).

3. **Configura y Sube el Código**:
   - Abre el archivo `calidad_aire.ino` en el IDE de Arduino.
   - Selecciona la placa ESP32 y el puerto COM correcto.
   - Sube el código al ESP32.

---

## **Cálculos Implementados**

### **Cálculo de Rs**
Rs se calcula a partir de un divisor de tensión:

\[
Rs = RL \times \left( \frac{Vs - Vm}{Vm} \right)
\]

Donde:
- RL: Resistencia de carga (20 kΩ).
- Vs: Voltaje de alimentación (5V).
- Vm: Voltaje medido por el ESP32.

### **Cálculo de Ro**
Ro se determina en aire limpio usando la relación Rs/Ro proporcionada por la hoja de datos del sensor:

- Para el MQ135: Rs/Ro = 3.8.
- Para el MQ9: Rs/Ro = 9.9.

### **Cálculo de PPM**
Se utiliza una relación logarítmica entre Rs/Ro y PPM:

\[
PPM = 10^{\frac{\log(Rs/Ro) - b}{m}}
\]

Donde:
- m: Pendiente de la curva.
- b: Intersección de la curva.

Valores para los sensores:
- **MQ135**:
  - m = -0.3679
  - b = 0.815
- **MQ9**:
  - m = -0.4101
  - b = 1.075

---

## **Visualización en Pantalla OLED**

Los datos procesados se despliegan en la pantalla OLED con el siguiente formato:
- Concentración de CO₂ en PPM.
- Concentración de CO en PPM.
- Temperatura en °C.
- Humedad relativa en %.

---

## **Aplicaciones**

- Monitoreo de calidad del aire en espacios cerrados.
- Sistemas de automatización para el control ambiental.
- Proyectos educativos para aprender sobre sensores y cálculos logarítmicos.
- Base para sistemas IoT avanzados con envío de datos a la nube.

---

## **Contribuciones**
Este proyecto está abierto a mejoras. Si deseas contribuir, puedes hacerlo mediante pull requests o reportando problemas en la sección de issues.

---

## **Licencia**
Este proyecto está licenciado bajo [MIT License](LICENSE), por lo que es de uso libre para proyectos personales y educativos.

