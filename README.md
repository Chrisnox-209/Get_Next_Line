*This project has been created as part of the 42 curriculum by cpietrza.*

# Get Next Line

## 📝 Description

**Get Next Line** est un projet de l'école 42 dont l’objectif est d’écrire une fonction en C capable de lire **une ligne depuis un file descriptor**, de manière successive et efficace.
L’exercice introduit un concept essentiel : **les variables statiques**, nécessaires pour conserver un état entre plusieurs appels.

La fonction doit :

- Lire un fichier **ligne par ligne**, y compris depuis l'entrée standard.
- Gérer **tous types de BUFFER_SIZE** (petit, grand, 1, 9999…).
- Ne pas relire tout le fichier d’un coup : lire **le strict minimum à chaque appel**.
- Retourner la ligne **avec le '\n'**, sauf si la fin du fichier est atteinte sans retour à la ligne.
- Retourner **NULL** en cas d’erreur ou de fin de fichier.

---

## 🚀 Instructions

### 📦 Fichiers à rendre (partie obligatoire)
get_next_line.c
get_next_line_utils.c
get_next_line.h


### ⚙️ Compilation

Compiler avec un BUFFER_SIZE choisi :
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c


Le programme doit aussi compiler **sans** `-D BUFFER_SIZE`.

### ▶️ Exemple d'utilisation

```c
int main(void)
{
    int     fd = open("file.txt", O_RDONLY);
    char    *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
## 🧠 Algorithme & Explication technique

La fonction repose sur un principe clé :
➡️ **conserver dans une variable statique le contenu lu mais non encore retourné.**

---

### 🔍 Étapes principales

#### 1. Lecture progressive
- Lire avec `read()` par blocs de `BUFFER_SIZE`.
- Ajouter chaque bloc au *stash* jusqu’à trouver un `'\n'`.

#### 2. Extraction de la ligne
- Repérer le premier `'\n'` dans le stash.
- Extraire la ligne complète (incluant `\n` si présent).

#### 3. Mise à jour du stash
- Retirer du stash la ligne retournée.
- Conserver le reste pour l'appel suivant.

#### 4. Cas de fin
- Si aucun caractère restant → retourner `NULL`.
- Si fin du fichier sans `\n` mais stash non vide → retourner le stash entier.

---

### 📌 Pourquoi une variable statique ?
Pour mémoriser ce qui reste à lire entre deux appels successifs.
Sans elle, impossible de gérer une lecture "ligne par ligne".

---

## ⭐ Bonus

La version bonus ajoute :

- La gestion de **plusieurs file descriptors simultanément**.
- L'utilisation d’**un seul tableau statique**, indexé par fd.

Fichiers bonus :
get_next_line_bonus.c
get_next_line_bonus.h
get_next_line_utils_bonus.c


---

## 📚 Resources

### Références classiques
- Man `read()`
- Mécanisme des file descriptors
- `malloc` / `free` et gestion mémoire
- Variables statiques : https://en.wikipedia.org/wiki/Static_variable

## 👤 Auteur

* **Nom** : PIETRZAK Christophe
* **42 email** : cpietrza@student.42lyon.fr

## 🏆 NOTE
<img src="https://raw.githubusercontent.com/Chrisnox-209/Get_Next_Line/refs/heads/main/note.png" alt="Note get next line 42 Lyon" style="display:block; margin:auto;">
