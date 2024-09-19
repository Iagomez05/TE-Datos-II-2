#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "LinkedList.h"
#include "BinarySearchTree.h"
#include "grafico.h"

// Función para medir el tiempo de ejecución de un algoritmo
void measureTime(std::function<void(std::vector<int>&)> sortFunc, std::vector<int>& data, const std::string& sortName, double& tiempo) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(data);  // Llamada a la función de ordenamiento
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    tiempo = elapsed.count();
    std::cout << "Tiempo de ejecución (" << sortName << "): " << tiempo << " segundos" << std::endl;
}

int main() {
    // Datos de prueba para los algoritmos de ordenamiento
    std::vector<int> data = {64, 25, 12, 22, 11};
    std::vector<int> dataCopy;

    double tiempoBubbleSort, tiempoSelectionSort, tiempoMergeSort;

    // BubbleSort
    BubbleSort bubbleSort;
    dataCopy = data;
    measureTime([&bubbleSort](std::vector<int>& arr) { bubbleSort.sort(arr); }, dataCopy, "BubbleSort", tiempoBubbleSort);

    // SelectionSort
    SelectionSort selectionSort;
    dataCopy = data;
    measureTime([&selectionSort](std::vector<int>& arr) { selectionSort.sort(arr); }, dataCopy, "SelectionSort", tiempoSelectionSort);

    // MergeSort
    MergeSort mergeSort;
    dataCopy = data;
    measureTime([&mergeSort](std::vector<int>& arr) { mergeSort.sort(arr); }, dataCopy, "MergeSort", tiempoMergeSort);

    // LinkedList (Lista enlazada ordenada)
    LinkedList linkedList;
    linkedList.insert(10);
    linkedList.insert(5);
    linkedList.insert(20);
    std::cout << "Lista enlazada ordenada: ";
    linkedList.printList();

    // BinarySearchTree (Árbol binario de búsqueda)
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    std::cout << "BST (in-order): ";
    bst.inorderTraversal();

    // Crear vectores con los tiempos empíricos obtenidos
    std::vector<double> tiemposEmpiricos = {tiempoBubbleSort, tiempoSelectionSort, tiempoMergeSort};

    // Usamos los mismos tiempos para la gráfica teórica solo como referencia (puedes calcular los teóricos aparte)
    std::vector<double> tiemposTeoricos = {tiempoBubbleSort, tiempoSelectionSort, tiempoMergeSort};

    // Tamaños de entrada arbitrarios (ajústalos según el tamaño real de los datos)
    std::vector<int> n = {1, 2, 3};

    // Llamar a la función para dibujar el gráfico
    dibujarGrafico(tiemposEmpiricos, tiemposTeoricos, n);

    return 0;
}
