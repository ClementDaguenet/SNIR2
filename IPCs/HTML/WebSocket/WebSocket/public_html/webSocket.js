$(function ()
{
    var maWebsocket;
    if (window.WebSocket)
    {
        maWebsocket = new WebSocket('ws://172.18.58.146:8888');

        maWebsocket.onopen = function ()
        {
            console.log("ouverture webSocket");
        };
        maWebsocket.onclose = function (event)
        {
            console.log("code de a la fermeture : " + event.code);
            console.log("raison de la fermeture : " + event.reason);
        };
        maWebsocket.onerror = function ()
        {
            console.log("erreur sur la webSocket");
        };
        maWebsocket.onmessage = function (donneesRecues)
        {
            console.log("reception de donnees : " + donneesRecues.data);
            $("#ladate").text(donneesRecues.data);
            console.log("origine : " + donneesRecues.origin);
        };
    }
    $("#demande").click(function () {
        maWebsocket.send("date");
    });
});