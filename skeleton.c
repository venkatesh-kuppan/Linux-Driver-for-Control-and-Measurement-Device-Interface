#include <linux/comedidev.h>


typedef struct {
	char *name;
	int ai_chans;
	int ai_bits;
	int have_dio;
}interface_board;

static interface_board intb = {"CMDI", 8, 8, 0};

static int interface_attach(comedi_device *dev, comedi_devconfig *it);
static int interface_detach(comedi_device *dev);
static int interface_ai_rinsn(comedi_device*, comedi_subdevice*,
	comedi_insn*, lsampl_t*);

static comedi_driver driver_interface = {
	driver_name: "CMDI_driver",
	module: THIS_MODULE,
	attach: interface_attach,
	detach: interface_detach
};

static int interface_attach(comedi_device *dev, comedi_devconfig *it)
{
	comedi_subdevice *s;

	printk("Device: dev = %x\n", dev);
	dev->board_name = "Dummy Device, Venkatesh";
	if(alloc_subdevices(dev, 1) < 0)
		return -ENOMEM;

	s = dev->subdevices+0;
	s->type = COMEDI_SUBD_AI;
	s->subdev_flags = SDF_READABLE | SDF_GROUND;
	s->n_chan = intb.ai_chans;
	s->maxdata = (1 << intb.ai_bits) - 1;
	s->range_table = &range_unipolar5;
	s->insn_read = interface_ai_rinsn;

	return 1;
}

static int interface_ai_rinsn(comedi_device *dev, comedi_subdevice *s,
comedi_insn *insn, lsampl_t *data)
{
	int i, n;
	printk("rinsn call success: channel = %d\n", CR_CHAN(insn->chanspec));
	printk("samples to read = %d\n", insn->n);
	n = insn->n;
	for(i = 0; i < n; i++)
		data[i] = 1234;
	return insn->n;

}

static int interface_detach(comedi_device *dev)
{
	printk("detach called: dev = %x\n", dev);
	return 0;
}

COMEDI_INITCLEANUP(driver_interface);
