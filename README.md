# Proposta di Tesi di Laurea

**Università degli Studi di Torino**  
**Dipartimento di Informatica**  
**Corso di Laurea in Informatica**  

---

### Titolo della Tesi Proposta
**Sviluppo di un Motore di Simulazione Astrobotanica e Crescita Procedurale 3D ad Alte Prestazioni Guidato da Modelli di Linguaggio (LLM)**

* **Candidato:** Dylan Timo 
* **Matricola:** 948853
* **Relatore Proposto:** 
* **Ambito Tecnologico:** Grafica Computazionale, C++ Moderno, Artificial Intelligence, Real-Time Systems  

---

## 1. Introduzione e Obiettivi del Progetto

La simulazione della crescita delle piante (*Computational Botany*) rappresenta un campo di ricerca interdisciplinare che coniuga grafica computazionale, fisica dei sistemi complessi e biologia vegetale. Con l'avvento delle esplorazioni spaziali a lungo termine (programmi NASA Artemis ed ESA MELiSSA), la comprensione di come le specie vegetali reagiscano a condizioni ambientali extraterrestri (es. gravità ridotta, spettri luminosi LED specifici, pressione atmosferica controllata) è diventata una priorità scientifica.

Il presente progetto di tesi si propone di sviluppare un'applicazione desktop ad alte prestazioni in **C++20 e OpenGL 4.5+** capace di modellare, simularne l'accrescimento e renderizzare in tempo reale strutture vegetali sottoposte a vincoli fisici e biologici sia terrestri che spaziali (Luna, Marte, orbita).

Un elemento fortemente innovativo del progetto risiede nell'integrazione di un **Modello di Linguaggio (LLM)** esecutivo tramite architettura asincrona. L'LLM agirà da "Astrobotanico Virtuale", traducendo le richieste in linguaggio naturale dell'utente in configurazioni parametriche JSON per il motore di simulazione.

---

## 2. Architettura Tecnologica e Stack Software

L'applicazione sarà sviluppata adottando un'architettura modulare nativa desktop per garantire le massime prestazioni di calcolo e di rendering frame-by-frame:

* **Linguaggio & Build System:** C++20, gestito tramite CMake per garantire la portabilità multipiattaforma.
* **API Grafica:** OpenGL 4.5+ per il rendering 3D accelerato via GPU, avvalendosi di *GLSL Compute Shaders* per l'elaborazione parallela dei fattori ambientali.
* **Interfaccia Utente (GUI):** *Dear ImGui*, integrata direttamente nel ciclo di rendering per fornire una dashboard interattiva con controlli in tempo reale, telemetria biologica e console chat LLM.
* **Motore LLM & Parsing:** Integrazione di `llama.cpp` (per inferenza locale ad alte prestazioni di modelli quantizzati come LLaMA 3 o Phi-3) o API REST via `libcurl`, abbinata alla libreria `nlohmann/json` per la strutturazione dei dati.
* **Librerie di Supporto:** GLFW (gestione finestre e input), GLM (matematica 3D e algebra vettoriale).

---

## 3. Modello Biologico-Fisico e Formule Fondamentali

A differenza dei tradizionali generatori procedurali basati solo sull'estetica, il simulatore adotterà una logica basata su vincoli fisici e fisiologici reali:

### 3.1. Legge del Minimo di Liebig (Tasso di Crescita)
Il tasso di crescita organico ($\Delta G$) della pianta sarà determinato dal fattore ambientale più limitante tra quelli disponibili nel sistema, secondo la formula:

$$\Delta G = \min(S_{\text{luce}}, S_{\text{acqua}}, S_{\text{azoto}}, S_{\text{fosforo}}, S_{\text{pressione}}) \times \eta_{\text{specie}}$$

### 3.2. Conflitto Tropico (Vettore di Accrescimento Vettoriale)
Sulla Terra, la direzione dei rami è dominata dal gravitropismo (risposta alla gravità). In ambienti a bassa gravità (es. Luna con $g = 1.62 \, \text{m/s}^2$), la pianta riorienta la propria struttura verso la fonte di luce (fototropismo). La nuova direzione di crescita $\vec{V}_{\text{growth}}$ sarà calcolata ad ogni nodo come combinazione lineare pesata:

$$\vec{V}_{\text{growth}} = w_g \cdot \vec{V}_{\text{gravity}} + w_l \cdot \vec{V}_{\text{light}}$$

dove i pesi $w_g$ e $w_l$ sono proporzionali rispettivamente all'accelerazione di gravità del corpo celeste e all'intensità del flusso fotonico sintetico (LED).

---

## 4. Ingegneria del Software: Gestione Asincrona e Multi-Threading

Una delle principali sfide informatiche del progetto riguarda la prevenzione del blocco del thread di rendering (Target: 60 FPS costanti) durante la generazione del testo da parte dell'LLM, che può richiedere diversi secondi di elaborazione.

* **Main Thread (Render Loop):** Gestisce il loop di rendering OpenGL a 60 FPS, aggiorna l'interfaccia ImGui e disegna le mesh della pianta e della serra.
* **Worker Thread (LLM Engine):** Gestisce la comunicazione asincrona con l'LLM (`llama.cpp` o API REST). Alla ricezione del prompt, genera il JSON strutturato e aggiorna la memoria condivisa utilizzando meccanismi di sincronizzazione sicura (`std::mutex`, `std::atomic`).

---

## 5. Piano di Lavoro e Roadmap (Sprint)

| Fase / Sprint | Obiettivi Tecnologici | Deliverable Concreto |
| :--- | :--- | :--- |
| **Sprint 1** | Setup CMake, GLFW, OpenGL 4.5, Dear ImGui. Implementazione interprete L-System 3D base. | Finestra 3D interattiva con albero procedurale navigabile e UI ImGui. |
| **Sprint 2** | Implementazione del motore di simulazione biologica, calcolo vettoriale del fototropismo/gravitropismo. | Animazione della crescita condizionata da slider (luce, gravità, acqua). |
| **Sprint 3** | Integrazione thread asincrono per LLM, System Prompting per conversione Text-to-JSON. | Console di chat funzionante che genera parametri di pianta e ambiente via prompt. |
| **Sprint 4** | Preset di ambienti spaziali (Luna/Marte), ottimizzazione mesh (Instancing), stesura tesi. | Applicazione completa ed esaustiva per il collaudo e la discussione. |

---

## 6. Valore Accademico e Risultati Attesi

Il progetto offre un eccellente banco di prova per dimostrare competenze avanzate in diversi settori dell'Informatica:
1. **Ingegneria del Software & C++ Moderno:** Gestione della memoria, programmazione concorrente/asincrona e sviluppo di motori custom.
2. **Computer Graphics:** Pipeline di rendering 3D, Shaders personalizzati, strutture dati ricorsive per geometrie complesse.
3. **Artificial Intelligence Application:** Utilizzo pratico degli LLM per il *Function Calling / Structured Output Generation* applicato a simulazioni scientifiche.