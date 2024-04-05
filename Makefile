msg:
	@echo 'Targets are: '
	@echo ' producer'
	@echo ' consumer'
	@echo ' run'
	@echo  ' clean'




consumer: ./cpp/consumer.cpp
	g++ "./cpp/consumer.cpp" -pthread -lrt -o ./out/consumer


producer: ./cpp/producer.cpp
	g++ "./cpp/producer.cpp" -pthread -lrt -o ./out/producer


output: ./cpp
	
	make producer
	make consumer
	clear
	./out/producer shmfile & ./out/consumer shmfile
