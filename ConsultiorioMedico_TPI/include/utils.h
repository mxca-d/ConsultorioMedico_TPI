#pragma once
#include "fecha.h"

bool horaValida(const char* hora);
bool cancelacionUsuario (const char* cadena);
bool cancelacionUsuario (int num);
bool cancelacionUsuario (float num);
bool validacionCaracteres (const char* cadena);
bool validacionCaracteres (const char* cadena, int tamanio);
bool validacionCaracteres (int num);
void todoMayuscula (char *pCadena);
void controlBufferEnter ();
bool validacionImportes (float precio);
void mostrarEspecialidades();
bool cargarEspecialidad(int opcion, char* especialidad);
void mostrarDiaAgenda (int indice);
void mostrarHoraTurno (int indice);
bool cargarHoraTurno(int opcion, char* hora);
Fecha obtenerFechaBase(int opcion);
void obtenerDias(int opcion, Fecha *dias, Fecha hoy);
