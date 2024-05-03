# TrabajoFinalPrestamos


Abrir el archivo .cpp para la visualizacion del programa, descargar o copiar y pegar en el ide para la ejecucion 
% Parámetros del sistema
wn = 1; % Frecuencia natural
zita_values = 0.6:0.1:0.9; % Valores de zita de 0 a 2 con paso de 0.1

% Inicializar figura
figure;
hold on;

% Iterar sobre diferentes valores de zita
for zita = zita_values
    % Sistema de segundo orden
    sys = tf([wn^2], [1, 2*zita*wn, wn^2]);
    
    sys2=feedback(sys,1);
    % Respuesta al escalón
    step(sys2);
   
end

% Etiquetas y leyenda
xlabel('Tiempo');
ylabel('Respuesta');
title('Respuesta al escalón para diferentes valores de ζ');
legend('show');
grid on;
