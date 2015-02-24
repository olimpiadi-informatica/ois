# ois
Questo repository contiene i task di programmazione assegnati nel corso
delle Olimpiadi di Informatica a Squadre.

## Struttura delle cartelle

La struttura delle cartelle è `<anno>/<gara>/<nome>` dove:

* `<anno>` è l'anno in cui si è svolta la finale dell'edizione
  delle OIS (per esempio: 2015, se si tratta delle OIS la cui gara
  finale si è svolta il 23 febbraio 2015).
* `<gara>` è uno tra *pratica*, *finale*, *gara1*, *gara2*, *gara3* (e
  così via).
* `<nome>` è il nome breve del task.

## Formato dei task

Il formato utilizzato, al momento, è il cosiddetto *Italian format*.

* `<nome>/`
    * `task.yaml`: il file che definisce nome breve (uguale al nome
      della cartella), il nome, il tempo limite, la memoria limite, e
      così via.
    * `gen/`
        * `GEN`: file usato per descrivere gli input. Le parti della
          riga dopo un `#` vengono ignorate. Le righe non banali (ovvero
          contenenti qualcosa oltre a whitespace prima del primo `#`)
          vengono passate al generatore e generano un input ciascuna.
          Se una riga inizia con `#ST:` viene usata per delimitare un
          subtask. `#ST:` va seguito con il punteggio assegnato a quel
          subtask. Se sono presenti i subtask, è necessario che la somma
          dei punti di ogni subtask sia 100. Se una riga inizia con
          `#COPY:` allora ciò che segue viene interpretato come un
          percorso relativo a `<nome>/` dal quale andare a copiare un
          input esistente.
        * `generatore.*`: programma che per una certa lista di argomenti
          produce (su *stdout*) un certo input valido.
        * `valida.*`: programma che dato un percorso (e se necessario
          anche il numero del subtask) come argomento verifica se a quel
          percorso c'è o no un file di input valido.
    * `sol/`
        * `soluzione.*`: la soluzione ufficiale. Viene usata per
          generare gli output.
        * `<altro>`: eventuali altre soluzioni (ad esempio: `lenta.cpp`,
          `quadratica.pas`, etc) che vengono valutate automaticamente
          dal comando cmsMake.
    * `testo/`
        * `italian.tex`: il testo.
