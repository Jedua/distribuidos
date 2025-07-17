# Lista de emuladores a lanzar (ajusta según tu entorno)
$emuladores = @(
    "flutter_emulator",
    "Medium_Phone_API_36.0"
)

# Lanza emuladores
foreach ($emu in $emuladores) {
    Write-Host "Lanzando emulador: $emu"
    Start-Process "flutter" -ArgumentList "emulators", "--launch", $emu
    Start-Sleep -Seconds 10
}

# Espera a que los emuladores estén activos
Write-Host "Esperando que los emuladores estén listos..."
Start-Sleep -Seconds 20

# Verifica dispositivos activos
$dispositivos = flutter devices | Select-String "emulator-"

# Ejecuta Flutter en cada emulador
foreach ($linea in $dispositivos) {
    if ($linea -match "(emulator-\d{4})") {
        $id = $matches[1]
        Write-Host "Ejecutando Flutter en $id"
        Start-Process "flutter" -ArgumentList "run", "-d", $id
        Start-Sleep -Seconds 5
    }
}
