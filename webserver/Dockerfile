# FROM python:3.12-alpine
FROM alpine:3.22.4

WORKDIR /app

RUN apk add --no-cache python3 py3-pip

# RUN python3 -m venv env 
# RUN env/bin/activate
COPY requirements.txt .

RUN pip install --no-cache-dir -r requirements.txt --break-system-packages
# COPY env/ .
# COPY ./packages-1 /app/packages
# RUN pip install --no-index --find-links=/app/packages -r requirements.txt
# RUN pip install --no-index --find-links=file:///app/packages -r requirements.txt

COPY main.py .

EXPOSE 8080

# bind 0.0.0.0 so it's accessible outside the container
CMD ["python", "main.py"]
