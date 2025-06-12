struct Posicion {
    int x;
    int y;
};

enum TipoUber {
    UBER_PLANET = 0,
    UBER_XL = 1,
    UBER_BLACK = 2
};

struct InfoAuto {
    int disponible;
    struct Posicion pos;
    enum TipoUber tipo;
    int tarifa;
    string placas<16>;
};

struct InfoServicio {
    int viajes;
    int libres;
    int ganancia;
};

struct TerminaViajeArgs {
    struct Posicion pos_final;
    int costo;
    string placas<16>;
};

program UBERPROG {
    version UBERVERS {
        InfoAuto solicitar_viaje(Posicion) = 1;
        void terminar_viaje(TerminaViajeArgs) = 2;
        InfoServicio estado_servicio(void) = 3;
    } = 1;
} = 0x20000010;
