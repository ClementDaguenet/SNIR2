var maWebsocket;
function desactiverDialogue(bool)
{
    $("#affichage").prop("disabled", bool);
    $("#message").prop("disabled", bool);
    $("#envoyer").prop("disabled", bool);
    $("#deconnexion").prop("disabled", bool);
}
function connexion(event)
{
    // empecher l'envois du formulaire
    event.preventDefault();

    // l'API WebSocket est-elle installee ?
    if (window.WebSocket)
    {

        // creation de la WebSocket
        maWebsocket = new WebSocket('ws://' + $("#ipServeur").val() + ':' + $("#portServeur").val());

        //Gestion des evenements de la WebSocket
        maWebsocket.onopen = function ()
        {
            console.log("ouverture webSocket");
            $("#affichage").append("Connexion au serveur\n");
            desactiverDialogue(false);
            $("#formConnexion").hide();
        };
        maWebsocket.onclose = function (event)
        {
            console.log("Code de a la fermeture : " + event.code);
            console.log("Raison de la fermeture : " + event.reason);
            $("#affichage").append("Déconnexion du serveur" + event.reason + "\n");
            desactiverDialogue(true);
            $("#formConnexion").show();
        };
        maWebsocket.onerror = function ()
        {
            console.log("Erreur sur la webSocket");
            $("#affichage").append("une erreur\n");
        };
        maWebsocket.onmessage = function (donneesRecues)
        {
            console.log("reception de donnees : " + donneesRecues.data);
            console.log("origine : " + donneesRecues.origin);
            // ajouter le texte reçu à la zone d'affichage
            $("#affichage").append(donneesRecues.data + "\n");
            //scrooler en bas de la textarea
            $('#affichage').scrollTop($('#affichage')[0].scrollHeight);
        };
    }
}
function envoyerMessage(event)
{
    // empecher l'envois du formulaire
    event.preventDefault();
    // envoyer pseudo : message
    maWebsocket.send($("#pseudo").val() + " : " + $("#message").val());
    // vide le champs message
    $("#message").val("");
    
}
function deconnexion()
{
    maWebsocket.close();
}
$(document).ready(function () {
    desactiverDialogue(true);
    $("#formConnexion").submit(connexion);
    $("#deconnexion").click(deconnexion);
    $("#formDialogue").submit(envoyerMessage);

});

