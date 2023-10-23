## Algorithmen und Datenstrukturen (ADS)
### Die Projektmappe enthält Beispielprogramme zu der Vorlesung Algorithmen und Datenstrukturen (ADS)

Der Aufbau der Projektmappe (ADS.sln) ist wie folgt:

| Projektmappen-Ornder | Projekt            | Inhalt                                                               | Verweis auf Skript |
|----------------------|--------------------|----------------------------------------------------------------------|--------------------|
| **ADS Kapitel 1**    | 01_Datenstrukturen | Beispielhafter Aufbau einer allgemeinen Datenstruktur            	   | K1 Folie 11/12 	|
|                      | 02_StdVectorBsp    | Beispiel für den Umgang mit einem std::vector / Variationen for-loop | K1 Folie 13        |
|					   | 03_InsertionSort   | Beispielprogramm Insertionsort (mit Usereingabe)					   | K1 Folie 26		|
|					   | 04_MergeSort       | Beispielprogramm Mergesort (mit Usereingabe)						   | 					|
| **ADS Kapitel 2**    | 01_Array           | Umgang mit Pointern                                                  | K2 Folie 7-9       |
|					   | 02_Stack   	    | Implementierung eines Stacks + Grundgrrüst für Übungsblatt 2 A2, A3, A5   | K2 Folie 17-23 	|
|					   | 02_Stack_solution  | Lösung von Übungsblatt 2 A2 + A3 + A5								   | Übungsblatt 2 A2,A3,A5 |
|					   | 03_Queue  			| Implementierung einer Queue als Ringpuffer						   | K2 Folie 27-28		|
|					   | 04_PriorityQueue   | Implementierung einer PQ als verkettete Liste, Array und Min-Heap	   | K2 Folie 43-45		|
|					   | 05_LinkedList      | Implementierung einer einfach verketteten Liste (mit und ohne expliziten Head(Tail)-Knoten) + Anwendungsbeispiele: Stack und Queue auf Basis einer verketteten Liste	| K2 31-33 |
|					   | 06_DoublyLinkedList| Implementierung einer doppelt verketteten Liste + Grundgrrüst Übungsblatt 2 A6+A7					   | K2 34-38			|
|					   | 06_DoublyLinkedList_solution | Lösung von Übungsblatt 2 A6 + A7						   | Übungsblatt 2 A6+A7	|
|					   | 07_Uebung1_A1		| Musterlösung für Aufgabe 1 von Übungsblatt 1						   | Übungsblatt 1 A1	|
|					   | 08_Uebung1_A4		| Musterlösung für Aufgabe 4 von Übungsblatt 1		 				   |  Übungsblatt 1 A4  | 
|					   | 09_Uebung2_A1		| Musterlösung für Aufgabe 1 von Übungsblatt 2						   |  Übungsblatt 2 A1  | 
| **ADS Kapitel 3**    | 01_BST_Array       | Binärer Suchbaum                                                     | K3   |
|					   | 02_BST_nullNode	| BST Implementierung mit NullNode für die Blätter 					   | K3     |
|					   | 03_BST_nullNode_parent | BST Implementierung mit NullNode für die Blätter und Zeiger auf den Elternknoten | K3  |
|				       | 04_BST_nullptr			| BST Implementierung mit nullptr in den Blättern 				   | K3 |
| 					   | 05_BST_nullptr_parent | BST Implementierung mit nullptr in den Blättern und Zeiger auf den Elternknoten | K3  |
|					   | 06_Uebung3			| Grundgrrüst für Übungsblatt 3 									   | Übungsblatt 3 |
|					   | 07_Uebung3_solution | Lösung für Übungsblatt 3 										   | Übungsblatt 3 |	
| **ADS Kapitel 4**    | 01_Fibonacci		| Fibonacci-Zahlen berechnen (rekursiv/iterativ + Zeitmessung)			| K4 Teil 2 |
| **ADS Kapitel 5**    | 01_AVL-Tree		| Implementierung eines AVL-Trees (Template + unique_ptr) --> Augfabe: löschen | K5 |
| **ADS Kapitel 6**    | 01_SimpleSort 		| Implementierung der Grundlegenden Sortieralgorithmen (Insertion-Sort, Selection-Sort, Bubble-Sort, Shell-Sort) | K6 Teil 1 |
| 					   | 02_FastSort		| Implementierungen von schnellen Sortieralgorithmen (Merge-Sort, Heap-Sort, Quick-Sort) | K6 Teil 2 |
| **ADS Kapitel 8**    | 01_Grad     		| Implementierung der Algorithmen zur bestimmung des Grades                                         | K8 Folie 22        |
| 					   | 02_node2adjl		| Implementierung von einem Algorithmus zur Umwandlung einer Knotenliste in eine Adjazenzliste      | K8 Folie 35        |
| 					   | 03_tiefensuche		| Implementierungen von verschieden Algorithmen mithilfe von Tiefensuche                            | K8 Algorithmen 1-7 |
| 					   | 04_breitensuche	| Implementierung von einem Algorithmus zur iterativen Breitensuche                                 | K8 Algorithmus 9   |
| 					   | 05_kantengewichtet	| NICHT FERTIG                                                                                      | K8                 |


##### Ausführen der Beispielprogramme:
- Um ein Projekt zu starten, muss es in Visual Studio 2019 (VS2019) als Startprojekt festgelegt werden - hierfür einfach ein Rechtsklick auf das gewünschte Projekt und den Eintrag "Als Startprojekt festlegen" wählen. 
- Jedes Projekt enthält eine eigene main-Funktion (in diesem Fall auch immer die Datei main.cpp). Hier startet das jeweilig Projekt und hier werden die Datenstrukturen erstellt und modifiziert.


##### Hinweis Version:
- Die Projektmappe wurde mit **VS2019** erstellt und der zugehörige **64-bit Compiler** in der Version **v142** verwendet. Dieses Setting sollte bei einer standardmäßigen Installation von VS2019 vorhanden sein.

