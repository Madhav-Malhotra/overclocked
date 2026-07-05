# FROM python:3.12-alpine
FROM alpine:3.22.4

WORKDIR /app

RUN apk add --no-cache python3 py3-pip

COPY requirements.txt .

RUN pip install --no-cache-dir -r requirements.txt --break-system-packages

COPY main.py .

EXPOSE 8080

# bind 0.0.0.0 so it's accessible outside the container
CMD ["python", "main.py"]
