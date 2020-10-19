# Titulo
  El proyecto desarrollado en este repositorio corresponde a un juego retro estilo laberinto en 2D. El juego está desarrollado en C++ y utiliza como librería principal SDL2. La principal razón por la cual se desarrollo un proyecto de este estilo fue poner en practica y usar las estructuras de datos estudiadas en el curso.
  
## Grupo desarrollador
  Ambos desarrolladores son estudiantes del Instituto Tecnológico de Costa Rica y cuyos nombres son:
  
**Victor**
  Correos electrónicos:
  - victorjulio345@gmail.com
**Jordán Guzmán Salas**
  Correos electrónicos:
  - jordan-guzman-salas@hotmail.com
  - jorggss01@gmail.com
  
  
## Historia del juego

## Principales estructuras de datos creadas
 
**Matriz para pintado del mapa**

Se creó una matriz de 20x25 para manejar el pintado del laberinto, siendo un valor 0 para una casilla, y un valor 1 para una pared.

**Matriz de manejo de coordenadas para las recompensas**
   Función que se usa para tener información sobre la ubicación exacta de las recompensas, una vez una de ellas es recogida, la coordenada es eliminada.
   
**Manejo de la posición y animaciones de sprites**
    Se hace manejo de las estructuras de datos SDL_Rect para el pintado de personajes y el laberinto. manejando las posiciones de estos mediante el incremento 
   o decremento de los valores de la estructura.

## Metodos principales
  **Pintado del laberinto**
  Se recorre una estructura matricial para reconocer donde pintar los sprite siendo el laberinto el que indica donde se debe colocar un sprite específico.
  **Crear las recompensas**
  Se encarga de generar una posicion aleatoria y agregarla al laberinto, para que luego este cuando proceda a pintarlo, cuando se recoja la recompensa esta pasa a ser borrada del laberinto por lo que cuando se actualiza, no se vuelve a imprimir. Esta tambien almacena la coordenada de la recompensa para en una estructura matricial, para que asi se pueda saber la posición exacta para que esta pueda ser luego recogida.
  **Comprobar recompensa**
  Se encarga de recoger la recompensa, este la elimina del mapa, reproduce un sonido, para ello compara la posición del jugador con la estructura con la de la recompensa recorriendo la matriz previamente fabricada,si estas son limitan, activa tanto el sonido como el borrado, y borra la coordenada de la estructura matricial,
  esta sujeta a cambios para fases futuras.
  **Muertes y vidas**
  Los enemigos carecen de programación por lo que se asigno a modo de prueba en el botón "m" para matar al primer jugador y "k" para el segundo, con esto se eliminan los personajes,vuelven a las posiciones iniciales y se decrementan las vidas, las cuales son compartidas, cuando se acaban las vidas, se termina el juego. Cada vez que un personaje muere se crea una explosion.
  **Personajes,animación y movimiento**
  El personaje se genera inmóvil,y cuando se mueve procede a animarse,para ello se recorre la estructura de datos correspondiente al sprite de personaje y se anima mediante de ticks, para el desplazamiento se alteran los valores de la posición "x" y "y" presentes en la estructura de datos SDL_Rect. 

## Analisis de resultados

## Biografia
- [1]S. Baquero, "SDL sonidos - ID-000244379", Sites.google.com, 2014. [Online]. Available: https://sites.google.com/site/id000244379/sdl/sdl-1. [Accessed: 19- Oct- 2020].
- [2]Code, Tech, and Tutorials, SOUND WITH C++ | PART 1 | SDL2 Mixer Walkthrough Tutorial How-To | Playing Sound Effects. 2020.
- [3]D. D'Agostino, "SDL2: Animations with Sprite Sheets", Programmersranch.com, 2014. [Online]. Available: https://www.programmersranch.com/2014/03/sdl2-animations-with-sprite-sheets.html. [Accessed: 19- Oct- 2020].
