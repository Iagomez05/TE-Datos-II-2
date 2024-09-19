# Comparación de Algoritmos de Ordenamiento

Este proyecto mide y compara los tiempos de ejecución de varios algoritmos de ordenamiento en C++ y genera gráficos utilizando **GTK+** y **Cairo**.
Se asume que todo el entorno de desarrollo ya está configurado (Dependencias).

## Algoritmos Implementados
- **BubbleSort**: \(O(n^2)\)
- **SelectionSort**: \(O(n^2)\)
- **MergeSort**: \(O(n \log n)\)

## Compilación (Se puede correr desde el IDE) CLion

### Windows (MSYS2):
g++ main.cpp grafico.cpp -o programa.exe $(pkg-config --cflags --libs gtk+-3.0 cairo)

### Linux/macOS:
g++ main.cpp grafico.cpp -o programa $(pkg-config --cflags --libs gtk+-3.0 cairo)


