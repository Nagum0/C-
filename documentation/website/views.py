from flask import Blueprint

views = Blueprint("views", __name__)

#This function will run if we got to the `/` root
@views.route("/")
def home():
    return "<h1>Test</h1>"