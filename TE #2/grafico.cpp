//
// Created by joelg on 18/9/2024.
//

#include "grafico.h"
#include <gtk/gtk.h>
#include <cairo.h>
#include <vector>

// Variables globales para almacenar los tiempos empíricos y teóricos
std::vector<double> tiemposEmpiricos;
std::vector<double> tiemposTeoricos;
std::vector<int> n;

// Función que dibuja los gráficos usando Cairo
gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
    // Dibujar ejes (X e Y)
    cairo_set_source_rgb(cr, 0, 0, 0); // Color negro
    cairo_move_to(cr, 50, 250); // Eje X
    cairo_line_to(cr, 450, 250); // Eje X hasta la derecha
    cairo_move_to(cr, 50, 250); // Eje Y
    cairo_line_to(cr, 50, 50); // Eje Y hacia arriba
    cairo_stroke(cr); // Dibuja los ejes

    // Dibujar los tiempos empíricos (en rojo)
    cairo_set_source_rgb(cr, 1, 0, 0); // Rojo
    for (size_t i = 0; i < tiemposEmpiricos.size() - 1; ++i) {
        cairo_move_to(cr, 50 + n[i] * 50, 250 - tiemposEmpiricos[i] / 2);
        cairo_line_to(cr, 50 + n[i + 1] * 50, 250 - tiemposEmpiricos[i + 1] / 2);
    }
    cairo_stroke(cr); // Dibuja la línea para los tiempos empíricos

    // Dibujar los tiempos teóricos (en azul)
    cairo_set_source_rgb(cr, 0, 0, 1); // Azul
    for (size_t i = 0; i < tiemposTeoricos.size() - 1; ++i) {
        cairo_move_to(cr, 50 + n[i] * 50, 250 - tiemposTeoricos[i] / 2);
        cairo_line_to(cr, 50 + n[i + 1] * 50, 250 - tiemposTeoricos[i + 1] / 2);
    }
    cairo_stroke(cr); // Dibuja la línea para los tiempos teóricos

    return FALSE;
}

// Función para iniciar el dibujo del gráfico, recibe los datos empíricos y teóricos
void dibujarGrafico(const std::vector<double>& emp, const std::vector<double>& teoricos, const std::vector<int>& tamN)
{
    // Guardar los datos en las variables globales
    tiemposEmpiricos = emp;
    tiemposTeoricos = teoricos;
    n = tamN;

    GtkWidget *window;
    GtkWidget *darea;

    // Inicializar GTK
    gtk_init(0, NULL);

    // Crear la ventana principal
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Comparación de Tiempos");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // Crear un área de dibujo
    darea = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), darea);

    // Conectar la señal para dibujar el gráfico
    g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(on_draw_event), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Mostrar la ventana
    gtk_widget_show_all(window);

    // Iniciar el bucle principal de GTK
    gtk_main();
}
