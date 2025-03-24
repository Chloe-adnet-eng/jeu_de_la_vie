# jeu_de_la_vie

Code du jeu de la vie en C++


## Le compilateur c++ utilisé est clang++

- Commande pour compiler un modèle cpp
    ```bash
        make compile fichier=<nom_fichier>
    ```
    Cette commande doit gnérer le fichier compilé `nom_fichier` dans le folder `build/` 
    

- Commande pour exécuter le fichier compiler 
    ```bash 
    make execute fichier_compile=nom_fichier
    ```

## L'interface graphique choisie est sfml

- Installer sfml sur MacOs 
    ```bash 
    brew install sfml
    ```

## Install CMake 
- Installer cmake sur MacOs 
    ```bash 
    brew install cmake
    ```

## Afficher la grille 
    ```bash
    cmake -B build
    ```

    ```bash
    cmake --build build
    ```

    ```bash
    ./build/bin/main 
    ```
