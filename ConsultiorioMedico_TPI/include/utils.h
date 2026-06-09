#pragma once

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
void mostrarTurnoAgenda (int indice);
