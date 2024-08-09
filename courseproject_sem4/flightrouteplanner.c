#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_AIRPORTS 100
#define MAX_FLIGHTS 1000

typedef struct AirportNode
{
    char code[4];
    char name[50];
    struct FlightNode *flights; // Adjacency list of flights departing from this airport
} AirportNode;

typedef struct FlightNode
{
    char flightNumber[10];
    struct AirportNode *departureAirport;
    struct AirportNode *arrivalAirport;
    char departureTime[10];
    char arrivalTime[10];
    int cost;
    struct FlightNode *nextFlight; // Next flight in the adjacency list
} FlightNode;

typedef struct Graph
{
    int numAirports;
    AirportNode *airports[MAX_AIRPORTS];
} Graph;

bool isNumeric(const char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
            return false;
        str++;
    }
    return true;
}

bool containsDigits(const char *str)
{
    while (*str)
    {
        if (isdigit(*str))
            return true;
        str++;
    }
    return false;
}

Graph *createGraph()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if (graph == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    graph->numAirports = 0;
    return graph;
}

AirportNode *createAirport(const char *code, const char *name)
{
    AirportNode *airport = (AirportNode *)malloc(sizeof(AirportNode));
    if (airport == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(airport->code, code);
    strcpy(airport->name, name);
    airport->flights = NULL;
    return airport;
}

FlightNode *createFlight(const char *flightNumber, AirportNode *departureAirport, AirportNode *arrivalAirport, const char *departureTime, const char *arrivalTime, int cost)
{
    FlightNode *flight = (FlightNode *)malloc(sizeof(FlightNode));
    if (flight == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(flight->flightNumber, flightNumber);
    flight->departureAirport = departureAirport;
    flight->arrivalAirport = arrivalAirport;
    strcpy(flight->departureTime, departureTime);
    strcpy(flight->arrivalTime, arrivalTime);
    flight->cost = cost;
    flight->nextFlight = NULL;
    return flight;
}

void addAirport(Graph *graph)
{
    if (graph->numAirports >= MAX_AIRPORTS)
    {
        printf("Maximum number of airports reached.\n");
        return;
    }

    char code[4];
    char name[50];
    printf("Enter airport code (3 characters): ");
    scanf("%3s", code);

    if (strlen(code) != 3 || !isNumeric(code))
    {
        printf("Invalid airport code. Airport code must be exactly 3 numeric characters.\n");
        return;
    }

    printf("Enter airport name: ");
    scanf(" %[^\n]", name);

    if (containsDigits(name))
    {
        printf("Invalid airport name. Airport name cannot contain numbers.\n");
        return;
    }

    graph->airports[graph->numAirports++] = createAirport(code, name);
    printf("Airport added successfully.\n");
}

void addFlight(Graph *graph)
{
    if (graph->numAirports < 2)
    {
        printf("There must be at least two airports to add a flight.\n");
        return;
    }

    char flightNumber[10];
    char departureCode[4];
    char arrivalCode[4];
    char departureTime[10];
    char arrivalTime[10];
    int cost;

    printf("Enter flight number: ");
    scanf("%9s", flightNumber);

    printf("Enter departure airport code (3 characters): ");
    scanf("%3s", departureCode);

    printf("Enter arrival airport code (3 characters): ");
    scanf("%3s", arrivalCode);

    printf("Enter departure time: ");
    scanf("%9s", departureTime);

    printf("Enter arrival time: ");
    scanf("%9s", arrivalTime);

    printf("Enter cost: ");
    scanf("%d", &cost);

    // Find departure airport
    AirportNode *departureAirport = NULL;
    for (int i = 0; i < graph->numAirports; ++i)
    {
        if (strcmp(graph->airports[i]->code, departureCode) == 0)
        {
            departureAirport = graph->airports[i];
            break;
        }
    }

    // Find arrival airport
    AirportNode *arrivalAirport = NULL;
    for (int i = 0; i < graph->numAirports; ++i)
    {
        if (strcmp(graph->airports[i]->code, arrivalCode) == 0)
        {
            arrivalAirport = graph->airports[i];
            break;
        }
    }

    if (departureAirport == NULL || arrivalAirport == NULL)
    {
        printf("One or both of the specified airports do not exist.\n");
        return;
    }

    FlightNode *newFlight = createFlight(flightNumber, departureAirport, arrivalAirport, departureTime, arrivalTime, cost);

    // Add flight to departure airport's adjacency list
    newFlight->nextFlight = departureAirport->flights;
    departureAirport->flights = newFlight;

    printf("Flight added successfully.\n");
}

void displayRoutes(Graph *graph)
{
    printf("Available flights:\n");
    for (int i = 0; i < graph->numAirports; ++i)
    {
        printf("From %s:\n", graph->airports[i]->name);
        FlightNode *flight = graph->airports[i]->flights;
        while (flight != NULL)
        {
            printf("\tFlight %s: %s -> %s, Departure: %s, Arrival: %s, Cost: $%d\n",
                   flight->flightNumber, flight->departureAirport->name, flight->arrivalAirport->name,
                   flight->departureTime, flight->arrivalTime, flight->cost);
            flight = flight->nextFlight;
        }
    }
}

int main()
{
    Graph *graph = createGraph();

    int choice;
    do
    {
        printf("\nFlight Route Planner Menu:\n");
        printf("1. Add Airport\n");
        printf("2. Add Flight\n");
        printf("3. Display Routes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addAirport(graph);
            break;
        case 2:
            addFlight(graph);
            break;
        case 3:
            displayRoutes(graph);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free allocated memory
    for (int i = 0; i < graph->numAirports; ++i)
    {
        FlightNode *flight = graph->airports[i]->flights;
        while (flight != NULL)
        {
            FlightNode *temp = flight;
            flight = flight->nextFlight;
            free(temp);
        }
        free(graph->airports[i]);
    }
    free(graph);

    return 0;
}
