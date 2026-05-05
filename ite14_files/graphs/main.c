#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Edge {
    char dest;
    int weight;
    struct Edge * next;
} Edge;
typedef struct Vertex {
    char value;         // value of the vertex
    int numOfEdges;   
    Edge * edges;
} Vertex;
typedef struct Graph {
       
    int numOfVertices;   
    Vertex ** vertices; 
} Graph;

Graph * createGraph() {
    Graph * newGraph = (Graph *)malloc(sizeof(Graph));
    if(newGraph == NULL) {
        printf("Error: failed to allocate memory for newGraph in createGraph().\n");
        return NULL;
    }
    newGraph->numOfVertices = 0;
    newGraph->vertices = (Vertex **)malloc(sizeof(Vertex *));
    return newGraph;
}

Vertex * createVertex(char value) {
    Vertex * newVertex = (Vertex *)malloc(sizeof(Vertex));
    if(newVertex == NULL) {
        printf("Error: failed to allocate memory for newVertex in createVertex().\n");
        return NULL;
    }
    newVertex->value = value;
    newVertex->edges = NULL;
    newVertex->numOfEdges = 0;
    return newVertex;
}

Edge * createEdge(char dest, int weight) {
    Edge * newEdge = (Edge *)malloc(sizeof(Edge));
    if(newEdge == NULL) {
        printf("Error: failed to allocate memory for newEdge in createEdge().\n");
        return NULL;
    }
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}


bool isExistVertex(Graph * graph, char target) {
    if(graph == NULL) {
        printf("Error: graph is null when isExistVertex().\n");
        return false;
    }
    int i;
    for(i = 0; i < graph->numOfVertices; i++) {
        if((graph->vertices)[i]->value == target)
            return true;
    }
    return false;
}

Vertex * searchVertex(Graph * graph, char target) {
    if(graph == NULL) {
        printf("Error: graph is null when searchVertex.\n");
        return NULL;
    }

    if(!isExistVertex(graph, target)) {
        printf("Error: target %c does not exist when searchVertex().\n", target);
        return NULL;
    }

    int i;
    for(i = 0; i < graph->numOfVertices; i++) {
        if((graph->vertices)[i]->value == target)
            return (graph->vertices)[i];
    }
    return NULL;
}

bool isExistEdge(Graph * graph, char vertex, char dest){
    if(graph == NULL) {
        printf("Error: graph is null when isExistEdge().\n");
        return false;
    }

    Vertex * targetVertex = searchVertex(graph, vertex);
    if(targetVertex == NULL)
        return false;
    
    Edge * edgeStart = targetVertex->edges;
    while(edgeStart != NULL){
        if(edgeStart->dest == dest)
            return true;
        edgeStart = edgeStart->next;
    }
    return false;
}

void insertVertex(Graph * graph, char value) {
    if(graph == NULL) {
        printf("Error: graph is null in insertVertex().\n");
        return;
    }
    if(isExistVertex(graph, value)) {
        printf("Function: %c already exists. Dumped value. insertVertex()).\n", value);
        return;
    }
    (graph->numOfVertices)++;
    graph->vertices = (Vertex **)realloc(graph->vertices, (graph->numOfVertices) * sizeof(Vertex *));
    (graph->vertices)[(graph->numOfVertices) - 1] = createVertex(value);
}


void connectVertices(Graph * graph, char start, char dest, int weight) {
    if(graph == NULL) {
        printf("Error: graph is null when connectVertices().\n");
        return;
    }
    if(!(isExistVertex(graph, start) && isExistVertex(graph, dest))) {
        printf("Error: either vertex %c or %c does not exist when connectVertices().\n", start, dest);
        return;
    }
    if(isExistEdge(graph, (searchVertex(graph, start))->value, dest)) {
        printf("Function: edge from %c to %c already exists. Dumping edge. connectVertices().\n", start, dest);
        return;
    }
    Vertex * vertex = searchVertex(graph, start);
    if(vertex == NULL) {
        printf("Error: failed to return vertex when connectVertices().\n");
        return;
    }
    if(vertex->edges == NULL) {
        vertex->edges = createEdge(dest, weight);
        (vertex->numOfEdges)++;
        return;
    }
    Edge * curr = vertex->edges;
    while(curr->next != NULL)
        curr = curr->next;
    
    curr->next = createEdge(dest, weight);
    
}

void printVertices(Graph * graph) {
    if(graph == NULL) {
        printf("Error: graph is null when printVertices().\n");
        return;
    }
    printf("Vertices: ");
    int i;
    for(i = 0; i < graph->numOfVertices; i++)
        printf("%c ", (graph->vertices)[i]->value);
    printf("\n");
}

void printEdges(Graph * graph, char vertexTarget) {
    if(graph == NULL) {
        printf("Error: graph is null when printEdges().\n");
        return;
    }
    Vertex * vertex = searchVertex(graph, vertexTarget);
    Edge * start = vertex->edges;
    printf("Vertex %c: ", vertexTarget);
    while(start != NULL) {
        printf("%c, ", start->dest);
        start = start->next;
    }
    printf("\n");
}

bool isVisited(char * visited, char node, int count) {
    int i;
    for(i = 0; i < count; i++) {
        if(visited[i] == node)
            return true;
    }
    return false;
}

// depth first search
void dfs(Graph * graph, char start) {
    int visitCount = 0;
    char * visited = (char *)malloc(sizeof(char));
    Vertex * vertex = searchVertex(graph, start);
    if(vertex == NULL) {
        printf("Error: start vertex %c does not exist. dfs()\n", start);
        return;
    }
    Edge * edgeStart = NULL;

    while(visitCount < graph->numOfVertices) {
        if(!isVisited(visited, vertex->value, visitCount)) {
            visitCount++;
            visited = (char *)realloc(visited, visitCount * sizeof(char));
            visited[visitCount - 1] = vertex->value;
            edgeStart = vertex->edges;
            while(edgeStart != NULL) {
                if(!isVisited(visited, edgeStart->dest, visitCount)) {
                    vertex = searchVertex(graph, edgeStart->dest);
                    break;
                }
                edgeStart = edgeStart->next;
            }
        }
    }

    int i;
    for(i = 0; i < visitCount; i++)
        printf("%c, ", visited[i]);
}

int main() {
    Graph * graph = createGraph();
    insertVertex(graph, 'A');
    insertVertex(graph, 'B');
    insertVertex(graph, 'C');
    insertVertex(graph, 'D');
    insertVertex(graph, 'E');
    insertVertex(graph, 'F');
    insertVertex(graph, 'G');
    
    printVertices(graph);

    connectVertices(graph, 'A', 'B', 1);
    connectVertices(graph, 'A', 'C', 1);
    connectVertices(graph, 'B', 'G', 1);
    connectVertices(graph, 'B', 'A', 1);
    connectVertices(graph, 'C', 'A', 1);
    connectVertices(graph, 'C', 'G', 1);
    connectVertices(graph, 'C', 'F', 1);
    connectVertices(graph, 'D', 'E', 1);
    connectVertices(graph, 'E', 'D', 1);
    connectVertices(graph, 'E', 'F', 1);
    connectVertices(graph, 'F', 'C', 1);
    connectVertices(graph, 'F', 'G', 1);
    connectVertices(graph, 'F', 'E', 1);
    connectVertices(graph, 'G', 'B', 1);
    connectVertices(graph, 'G', 'F', 1);
    connectVertices(graph, 'G', 'C', 1);

    printEdges(graph, 'A');
    printEdges(graph, 'B');
    printEdges(graph, 'C');
    printEdges(graph, 'D');
    printEdges(graph, 'E');
    printEdges(graph, 'F');
    printEdges(graph, 'G');

    dfs(graph, 'A');
}